//
///*
//
//// Bai 2
//#include <iostream>
//
//using namespace std;
//
//int a, b;
//long long c;
//
//void init() {
//	cout << "Khoi tao:   " << endl;
//	do {
//		cout << " - Nhap vao gia tri cua a:   ";
//		cin >> a;
//	} while (10 > a || a > 50);
//	
//	do {
//		cout << " - Nhap vao gia tri cua b:   ";
//		cin >> b;
//	} while (10 > b || b > 50 || a>=b);
//
//	c = a*b;
//}
//
//void timUoc(int a) {
//	int i;
//	for (i = 1; i < a ; i++) {
//		if (a%i == 0) {
//			cout << "  " << i;
//		}
//	}
//	cout << endl;
//}
//
//int checkPP(int a) {
//	int i;
//	long sum;
//	sum = 1;
//
//	for (i = 2; i < a ; i++) {
//		if (a%i == 0) {
//			sum += i;
//		}
//	}
//
//	if (sum > a)
//		return 1;
//	return 0;
//}
//
//
//int main() {
//
//	init();
//
//	// Cau 1
//	cout << endl << "Cau 1:   " << endl;
//	timUoc(c);
//
//	// Cau 2
//	cout << endl << "Cau 2:   " << endl;
//	cout << " - C = " << c << endl;
//	if (checkPP(c))
//		cout << " - " << c << " la so phong phu" << endl;
//	else
//		cout << " - " << c << " khong la so phong phu" << endl;
//
//	// Cau 3
//	cout << endl << "Cau 3:   " << endl;
//	for (int i = a; i <= b; i++) {
//		if (checkPP(i))
//			cout << "  " << i;
//	}
//
//	cout << endl << endl;
//
//	system("pause");
//}


//
//// Bai 3
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string s;
//char KQ[65];
//int n;
//
//
//int check_Char(string s) {
//	int i, len;
//	len = s.length();
//	for (i = 0; i < len; i++) {
//		if (s[i] - 48 < 0 || s[i] - 48 > 9)
//			return 0;
//	}
//
//	return 1;
//}
//
//void init() {
//	int len;
//	cout << "Khoi tao:   " << endl;
//	
//	do {
//		cout << " - Nhap vao chuoi S:   ";
//		getline(cin, s);
//		len = s.length();
//	} while (1 > len || len > 20 || !check_Char(s));
//
//}
//
//unsigned long long convertToLong(string s) {
//	unsigned long long number = 0;
//	int i, len;
//
//	len = s.length();
//
//	for (i = 0; i < len; i++) {
//		number = number * 10 + s[i] - 48;
//	}
//
//	return number;
//}
//
//void convertToBinary(unsigned long long a) {
//	int i;
//	i = 0;
//	while (a) {
//		KQ[i] = a % 2 + 48;
//		a = a / 2;
//		i++;
//	}
//
//	n = i;
//}
//
//void valueMax() {
//	int i, flag, j;
//	char* output = (char*)calloc(n, sizeof(char));
//
//	flag = 0;
//	j = 0;
//	for (i = n - 1; i >= 0; i--) {
//		if (KQ[i] != '0') {
//			output[j] = KQ[i];
//			j++;
//		}
//		else {
//			if (flag == 0 && KQ[i] == '0')
//				flag = 1;
//			else {
//				output[j] = KQ[i];
//				j++;
//			}
//		}
//	}
//
//	// In KQ
//	for (i = 0; i < j; i++)
//		cout << output[i];
//
//
//}
//
//int main() {
//	int i;
//	unsigned long long value;
//	char* binary = (char*)calloc(n, sizeof(char));
//
//	// Cau 1
//	cout << endl << "Cau 1:   " << endl;
//	init();
//
//	// Cau 2
//	cout << endl << "Cau 2:   " << endl;
//	cout << "  " << s << " = ";
//	value = convertToLong(s);
//	convertToBinary(value);
//	for (i = n - 1; i >= 0; i--)
//		cout << KQ[i];
//
//	// Cau 3
//	cout << endl << "Cau 3:   " << endl;
//	cout << " - Gia tri cua S:   " << s << endl;
//	cout << " - Gia tri cua Sb la:   ";
//	for (i = n - 1; i >= 0; i--)
//		cout << KQ[i];
//
//	cout << endl << " - Gia tri cua Sb' la:   ";
//	valueMax();
//
//	cout << endl << endl;
//
//	system("pause");
//}




// Bai 1
#include <iostream>

using namespace std;

int a, b;

void init() {
	cout << "Khoi tao:   " << endl;
	cout << " - Nhap gia tri cua a:   ";
	cin >> a;
	cout << " - Nhap gia tri cua b:   ";
	cin >> b;
}

double TBC() {
	double KQ;
	KQ = (a + b)*1.0 / 2;

	return KQ;
}

int abs(int a) {
	if (a > 0)
		return a;
	return 0 - a;
}


int main() {
	init();
	double KQ;

	// Cau 1
	KQ = TBC();
	cout << endl << "Cau 1:   " << endl;
	cout << " - Trung binh cong cua " << a << " & " << b << " la:   " <<KQ;

	// Cau 2
	cout << endl << "Cau 2:   " << endl;
		if (abs(a) > abs(b))
			cout << "a^2 > b^2" << endl;
		else if (abs(a) < abs(b))
			cout << "a^2 < b^2" << endl;
		else
			cout << "a^2 = b^2" << endl;


	system("pause");
}
