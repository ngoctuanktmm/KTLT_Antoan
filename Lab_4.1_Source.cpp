// Lab 4.1


#include <iostream>
#include <stdlib.h>

using namespace std;

int n, m;
int a[21], b[21], c[42];

// Cau 1
void createArray() {
	int i;

	do {
		cout << " - Nhap gia tri cua n:   ";
		cin >> n;
	} while (10 > n || n > 20);

	// Khoi tao 2 mang A & B co n phan tu
	for (i = 0; i < n; i++) {
		a[i] = rand() % 500 + 10;
		b[i] = rand() % 500 + 10;
	}
}

void printArray(int *array, int len) {
	int i;

	for (i = 0; i < len; i++) {
		cout << "\t" << array[i];
	}
	cout << endl;
}

void chanA_LeB() {
	int i, j;
	j = 0;
	for (i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			c[j] = a[i];
			j++;
		}
		if (b[i] % 2 != 0) {
			c[j] = b[i];
			j++;
		}
	}
	m = j;
}

int mul_is_safe(int a, int b) {
	if (b > INT_MAX / a)
		return 0;
	return 1;
}

void mulArray() {
	int i, j;
	long long KQ;
	KQ = 1;

	for (i = 0; i < m; i++) {
		if (mul_is_safe(c[i], KQ)) {
			cout << c[i];
			KQ *= c[i];
			for (j = i-1; j >= 0; j--) {
				if (i != 0)
					cout << " * " << c[j];
			}
			cout << " = " << KQ << endl;
		}
		else {
			cout << "Integer Overflow" << endl << endl;
			return;
		}
	}
}

int main() {

	// Cau 1
	cout << "Cau 1: " << endl;
	createArray();

	// Cau 2
	cout << endl << "Cau 2:  " << endl;
	cout << " - Mang A:   " << endl;
	printArray(a, n);
	cout << " - Mang B:   " << endl;
	printArray(b, n);

	// Cau 3
	cout << endl << "Cau 3:  " << endl;
	chanA_LeB();
	cout << " - Mang C:   " << endl;
	printArray(c, m);

	// Cau 4
	cout << endl << "Cau 4:  " << endl;
	mulArray();

	//system("pause");
	return 0;
}
