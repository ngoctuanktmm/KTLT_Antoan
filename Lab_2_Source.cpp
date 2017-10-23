#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
using namespace std;
string SSS;

bool checkIntValue(string s)
{
	int s_length = s.length();

	int count = 0;
	int i;
	for (i = 0; i < s_length; i++)
	{
		if (s[i] == '0') count++;
	}
	if (count == s_length) return false;

	for (i = 0; i < s_length; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return false;
		}
	}

	return true;
}

bool checkFloatValue(string s)
{

	int countDot = 0;
	int i;
	int s_length = s.length();
	if (s_length == 1 && s[0] == '.') return false;

	printf("\n0 -> 9 = %d -> %d", '0', '9');
	for (i = 0; i < s_length; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			printf("\ns[%d] = [%c] = %d", i, s[i], s[i]);
			if (s[i] == '.') countDot++;
			else return false;
			if (countDot == 2) return false;
		}
	}

	return true;
}

int convertIntValue(string s)
{
	int s_length = s.length();
	int x = 0;
	int i;
	for (i = 0; i < s_length; i++)
	{
		x += (s[i] - '0') * pow(10, s_length - i - 1);
	}

	return x;
}

float convertFloatValue(string s)
{
	int s_length = s.length();
	int index = -1;
	int i;
	for (i = 0; i < s_length; i++)
	{
		if (s[i] == '.')
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		return convertIntValue(s);
	}

	string s1;
	string s2;
	s1.resize(index);
	s2.resize(s_length - index - 1);

	for (i = 0; i < index; i++)
	{
		s1[i] = s[i];
	}

	cout << "\ns1 = " << s1;

	int k = 0;
	for (i = index + 1; i < s_length; i++)
	{
		s2[k] = s[i];
		k = k + 1;
	}

	cout << "\ns1 = " << s2;

	float x1 = convertIntValue(s1);
	float x2 = (float) convertIntValue(s2) / pow(10, s2.length());

	return x1 + x2;
}

float inputPrice()
{
	string s;
	cout << "\nNhap gia: ";
	getline(cin, s);

	while (checkFloatValue(s) == false)
	{
		cout << "\nLoi. Nhap lai gia: ";
		getline(cin, s);
	}

	return convertFloatValue(s);
}

int inputNumber()
{
	string s;
	cout << "\nNhap so luong: ";
	getline(cin, s);

	while (checkIntValue(s) == false)
	{
		cout << "\nLoi. Nhap lai so luong: ";
		getline(cin, s);
	}

	return convertIntValue(s);
}

int main()
{
	float price = inputPrice();
	int number = inputNumber();

	cout << "\nGia ca = " << price;
	cout << "\nSo luong = " << number;

	_getch();
	return 0;
}
