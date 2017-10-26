#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <cstdlib>
using namespace std;

int BitCount(uint64_t);
bool Addition_Is_Safe_Bits(uint64_t, uint64_t, const int);
bool short_Addition_Is_Safe_Value(short, short);
bool Multiplication_Is_Safe_Bits(uint64_t, uint64_t, const int);
bool int_Multiplication_Is_Safe_Value(uint32_t, uint32_t);
bool shortValidation(string);
void addAnCharacter(char *, int, char);
char* DecimalToBinary(unsigned int);
char* AxorB(char *, char *);
int BinaryToDecimal(char *s);
unsigned int myPow(unsigned int, unsigned int, bool &);

int main()
{

#if 0 // Program 2
	string strMoney, strRate;

lb_input:
	do
	{
		// Dữ liệu nhập quy hết về chuỗi sau đó chuỗi được Validation
		cout << "Money: ";
		getline(cin, strMoney);
		cout << "Rate (e.g: for 10% enter 10): ";
		getline(cin, strRate);
	} while (!shortValidation(strMoney) || !shortValidation(strRate));
	if (atoi((char *)strMoney.c_str()) > SHRT_MAX || atoi((char *)strRate.c_str()) > 100)
		goto lb_input;

	short money = static_cast<short>(atoi((char *)strMoney.c_str()));
	short rate = static_cast<short>(atoi((char *)strRate.c_str()));

	float InterestRate = static_cast<float>(rate) / 100;
	cout << "Interest Rate: " << InterestRate << " %" << endl;
	cout << "---------------------------" << endl;

	cout << "Year\t\tGrowth\t\tNew balance" << endl;

	bool flag = true; // Đặt cờ phát hiện tràn số để từ đó đưa ra thông báo tràn số
	for (int i = 1; i <= 10; i++)
	{
		short increase = static_cast<short>(money * InterestRate);
		short newmoney = money + increase;

		if (!short_Addition_Is_Safe_Value(money, increase)) // Cách 2: if(!Addition_Is_Safe_Bits(money, increase, 15))
		{
			flag = false;
			break;
		}

		cout << i << "\t\t" << increase << "\t\t" << newmoney << endl;
		money = newmoney;
	}

	if (!flag)
	{
		cout << "Warning: Integer Error...!!" << endl;
		goto lb_input; // Nếu tràn số thì nhập lại và tính tiếp (Không bắt buộc, tùy để bài, có thể tràn số chỉ cần in ra thông báo mà không bắt nhập lại)
	}

	cout << "Total: " << money << endl;

#endif // 1 // Program 2

#if 1 // Program 3
	// unsigned int: 0 -> 4.294.967.295
	unsigned int x, y;

	// Input
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "------------------------" << endl;

	// Decimal To Binary
	char *bin_x1 = DecimalToBinary(x);
	char *bin_y1 = DecimalToBinary(y);

	cout << "Decimal To Binary" << endl;
	cout << x << "\t:\t" << bin_x1 << endl;
	cout << y << "\t:\t" << bin_y1 << endl;
	cout << "------------------------" << endl;

	// XOR
	/*char *bin_x2 = DecimalToBinary(x);
	char *bin_y2 = DecimalToBinary(y);*/
	char * xorStr = AxorB(bin_x1, bin_y1);

	cout << "X xor Y" << endl;
	cout << "   x\t\t" << x << "\t" << bin_x1 << endl;
	cout << "   y\t\t" << y << "\t" << bin_y1 << endl;
	cout << "x xor y\t\t" << BinaryToDecimal(xorStr) << "\t" << xorStr << endl;
	cout << "------------------------" << endl;

	// POW
	bool flag = true;
	cout << "POW(X, Y)" << endl;
	cout << "   x\t = \t" << x << endl;
	cout << "   y\t = \t" << y << endl;
	unsigned int z = myPow(x, y, flag);

	if (!flag)
		cout << "Warning: Integer Error..!!" << endl;
	cout << "------------------------" << endl;

	// free / delete
	free(bin_x1);
	free(bin_y1);
#endif // 1 // Program 3

	system("pause");
	return 0;
}

bool shortValidation(string str)
{
	// Hàm Validation một string xem nó có hợp lệ hay không
	// unsigned short: 0..65535
	if (str.length() > 5 || str.length() == 0)
		return false;

	for (int i = 0; i < str.length(); i++)
		if (str.at(i) < '0' || str.at(i) > '9')
			return false;

	// Số nhập vào phải ít nhất là 1 (Không bắt buộc nếu đề bài không yêu cầu)
	double num = atof((char *)str.c_str());
	if (num < 1)
		return false;

	return true;
}
int BitCount(uint64_t a)
{
	// Hàm đếm số bit của một số nguyên
	int bits = 0;
	while (a != 0)
	{
		++bits;
		a >>= 1; // Dịch phải một bit. Dịch đến khi a = 0 thì sẽ kết thúc vòng lặp
	};

	return bits;
}
bool Addition_Is_Safe_Bits(uint64_t a, uint64_t b, const int nBit)
{
	// Hàm kiểm tra phép cộng hai số nguyên xem liệu có bị tràn hay không
	uint64_t x = a + b;
	int x_bits = BitCount(x);	// Đếm xem x biểu diễn bởi bao nhiêu bit
	return (x_bits <= nBit);
}
bool short_Addition_Is_Safe_Value(short a, short b)
{
	// Tương tự hàm Addition_Is_Safe_Bits nhưng hàm này không kiểm tra theo số bit mà kiểm tra theo giá trị (value)

	/*
	SHRT_MAX = 32767, SHRT_MIN = -32768

	- Giả sử: a = 32000
	- Cho phép thực hiện cộng khi: b <= 767 (tức là: 32767 - a)

	- Giả sử: a = -32000
	- Cho phép thực hiện cộng khi: b >= -768 (tức là: -32768 - (a) )
	*/

	// Tổng quát với kiểu short: -32768..32767
	if ((a > 0) && (b > SHRT_MAX - a))
		return false; // Tràn trên
	if ((a < 0) && (b < SHRT_MIN - a))
		return false; // Tràn dưới

	return true;
}
void addAnCharacter(char *s, int vt, char gt)
{
	// Hàm thêm một ký tự vào một vị trí bất kỳ trong chuỗi s
	int n = strlen(s);
	for (int i = n - 1; i >= vt; i--)
		s[i + 1] = s[i];
	s[vt] = gt;
	s[n + 1] = '\0';
}
char* DecimalToBinary(unsigned int x)
{
	// Hàm chuyển đổi một số nguyên dương hệ 10 sang hệ 2
	char s[45];
	int i = 0;
	while (x != 0)
	{
		unsigned int tmp = x % 2;
		tmp += 48;
		s[i] = tmp;
		x /= 2;
		i++;
	}
	s[i] = '\0';
	// Mảng ký tự s[i] là một chuỗi các ký tự '0' và '1'. Để hiển thị đúng dạng nhị phân của số cần đọc theo thứ tự ngược từ cuối mảng về đầu mảng

	// Cấp phát động một mảng ký tự là dạng nhị phân của số thập phân. Hàm sẽ trả về mảng ký tự này
	int index = 0, len = i;
	char *str = (char *)malloc((len + 1) * sizeof(char));

	for (int j = i - 1; j >= 0; j--)
		str[index++] = s[j];
	str[index] = '\0';

	return str;
}
char* AxorB(char *a, char *b)
{
	/*
	Phép XOR thực hiện trên hai dãy bit cùng độ dài
	A	B	A^B
	0	0	 0
	0	1	 1
	1	0	 1
	1	1	 0
	Chuẩn hóa hai chuỗi cùng độ dài trước khi XOR
	VD:
	a = 10010110 => 8 ký tự
	b = 10110	 => 5 ký tự
	=> Cần phải thêm 3 ký tự vào chuỗi b
	*/

	int na = strlen(a);
	int nb = strlen(b);

	// Chuẩn hóa hai chuỗi
	if (na > nb)
		for (int i = 0; i < na - nb; i++)
			addAnCharacter(b, 0, '0');
	if (nb > na)
		for (int i = 0; i < nb - na; i++)
			addAnCharacter(a, 0, '0');

	// XOR
	int sizeXorStr = strlen(a) + 1;
	char *xorStr = (char *)malloc(sizeXorStr * sizeof(char));
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == b[i])
			xorStr[i] = '0';
		else
			xorStr[i] = '1';
	}
	xorStr[strlen(a)] = '\0';

	return xorStr;
}
int BinaryToDecimal(char *s)
{
	// Hàm chuyển đổi một chuỗi nhị phân sang một số nguyên
	int n = 0; // Giá trị thập phân sẽ trả về
	int length = strlen(s);
	int somu = length - 1;

	for (int i = 0; i < length; i++)
		n += (s[i] - 48) * pow((double)2, somu--);

	return n;
}
unsigned int myPow(unsigned int x, unsigned int y, bool &flag)
{
	// Hàm tính lỹ thữa x mũ y

	// Các trường hợp đặc biệt
	if (x == 0)
	{
		if (y != 0) return 0;
		else return 1;
	}
	if (y == 0) return 1;

	// POW
	uint64_t sum = 1;
	for (int i = 1; i <= y; i++)
	{
		if (!int_Multiplication_Is_Safe_Value(sum, x))//Cách 2: if (!Multiplication_Is_Safe_Bits(sum, x, 32)) 
		{
			flag = false;
			break;
		}
		sum *= x;
		cout << x << " ^ " << i << "\t =\t" << sum << endl;
	}

	return sum;
}
bool Multiplication_Is_Safe_Bits(uint64_t a, uint64_t b, const int nBit)
{
	// Hàm kiểm tra xem phép nhân hai số nguyên liệu có bị tràn số hay không
	uint64_t x = a * b;
	size_t x_bits = BitCount(x);
	return (x_bits <= nBit);
}
bool int_Multiplication_Is_Safe_Value(uint32_t a, uint32_t b)
{
	// Tương tự như hàm Multiplication_Is_Safe_Bits nhưng hàm này kiểm tra theo giá trị (value)

	/*
	UINT32_MAX = 4294967295, UINT32_MIN = 0

	VD: MAX = 100
	- Giả sử: a = 25
	- Cho phép thực hiện phép nhân khi: b <= 4 (tức là: MAX / a)
	*/

	if (a > 0 && b > UINT32_MAX / a)
		return false;

	return true;
}

// Ref: https://stackoverflow.com/questions/199333/how-to-detect-integer-overflow
/*
** NOTE:
- Đoạn mã trong cặp if-endif:
	#if 0
		// Code here
	#endif

	Trong đó:
	+ Với #if 0 hiểu là comment đoạn code đó lại
	+ Với #if 1 hiểu là bỏ comment đoạn code đó
*/
