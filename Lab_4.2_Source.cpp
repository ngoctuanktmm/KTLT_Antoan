// Lab 4.2
#include <iostream>
#include <string>

using namespace std;

string s1, s2;

int checkChar() {
	int i, len;

	len = s2.length();
	for (i = 0; i < len; i++)
		if (s2[i] - 48 < 0 || s2[i] - 48 > 9)
			return 0;

	return 1;
}

void inputString() {
	cout << " - Nhap chuoi S1:   ";
	getline(cin, s1);
	
	while (1) {
		cout << " - Nhap chuoi S2:   ";
		getline(cin, s2);

		if (!checkChar())
			cout << "  => " << "Input Validation" << endl << endl;
		else
			break;
	}
}

int checkNumber() {
	int i, len;
	len = s1.length();

	for (i = 0; i < len; i++)
		if (s1[i] - 48 >= 0 && s1[i] - 48 <= 9)
			return 1;

	return 0;
}

int checkSDTMobifone() {
	int i, len;
	len = s2.length();

	if (len==10 && s2[0] - 48 == 0 && s2[1] - 48 == 9 && s2[2] - 48 == 0) {
		for (i = 3; i < 10; i++) {
			if (s2[i] - 48 < 0 || s2[i] - 48 > 9)
				return 0;
		}
		return 1;
	}
	else
		return 0;
}

int checkSubString() {
	int i, j;
	int len, len_s1, len_s2, flag;
	char temp;

	len_s1 = s1.length();
	len_s2 = s2.length();

	if (len_s2 == 0)
		return 1;

	if (len_s1 >= len_s2) {
		for (i = 0; i <= len_s1 - len_s2; i++) {
			flag = 1;
			for (j = 0; flag&&j < len_s2; j++) {
				if (s1[i + j] != s2[j])
					flag = 0;
			}
			if (flag)
				return 1;
		}
	}
	
	return 0;
}

string addString(){
	string s3;
	int i, len_s1, len_s2, len;

	len_s1 = s1.length();
	len_s2 = s2.length();
	len = len_s1 + len_s2;

	for (i = 0; i < len; i++) {
		if (i < len_s1)
			s3 += s1[i];
		else
			s3 += s2[i - len_s1];
	}

	return s3;
}

void insertString(string s3) {
	string str_Insert = "Buffer_Overflow";
	char after;
	int i, len, flag;

	len = s3.length();

	cout << " - Chuoi S3:   " << s3 << endl;

	cout << " - Ban muon them vao sau ky tu nao:   ";
	cin >> after;

	cout << endl << "  => ";

	flag = 0;
	for (i = 0; i < len; i++) {
		if (s3[i] != after) {
			cout << s3[i];
		}
		else {
			cout << after << str_Insert;
			flag++;
		}
	}

	if (!flag)
		cout << str_Insert << endl;
}

int main() {

	string s1, s2, s3;
	// Cau 1
	cout << endl << "Cau 1:   " << endl;
	inputString();

	// Cau 2
	cout << endl << "Cau 2:   " << endl;
	if (checkNumber())
		cout << " - Chuoi S1 co chu so" << endl;
	else
		cout << " - Chuoi S1 khong co chu so" << endl;

	// Cau 3
	cout << endl << "Cau 3:   " << endl;
	if (checkSDTMobifone())
		cout << " - Chuoi S2 la SDT mang Mobifone" << endl;
	else
		cout << " - Chuoi S2 khong la SDT mang Mobifone" << endl;

	// Cau 4
	cout << endl << "Cau 4:   " << endl;
	if (checkSubString())
		cout << " - Chuoi S2 la tap con cua chuoi S1" << endl;
	else
		cout << " - Chuoi S2 khong la tap con cua chuoi S1" << endl;

	// Cau 5
	cout << endl << "Cau 5:   " << endl;
	cout << " - Chuoi S3 = S1 + S2:   ";
	s3 = addString();
	cout << s3 << endl;

	// Cau 6
	cout << endl << "Cau 6:   " << endl;
	insertString(s3);
	cout << endl << endl;


	//system("pause");
  
  return 0;
}
