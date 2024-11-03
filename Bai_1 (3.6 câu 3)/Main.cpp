#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct {
	int tu;
	int mau;
} fraction;


//a. Viết hàm nhập vào một phân số
static void inputFraction(fraction* f) {

	do {
		cout << "Nhap tu so: ";  cin >> f->tu;
		cout << "Nhap mau so: ";  cin >> f->mau;
	} while (f->mau == 0);

}

//b. // Hàm nhập một dãy gồm n phân số
static void inputListFraction(fraction* listF, int n) {

	for (int i = 0; i < n; i++) {
		inputFraction(&listF[i]);
	}

}
// Hàm xuất một phân số
static void outFraction(fraction* f) {

	cout << f->tu << "/" << f->mau;

}

// Hàm xuất một dãy gồm n phân số
static void outListFraction(fraction* listF, int n) {

	for (int i = 0; i < n; i++) {
		outFraction(&listF[i]);
		cout << "\t";

	}

}

static fraction findLarger(fraction* f1, fraction* f2) {

	fraction result = *f1;

	if ((f1->tu * f2->mau - f2->tu * f1->mau) < 0) {
		result = *f2;
	}

	return result;
}

//e. Viết hàm tìm phân số lớn nhất trong dãy phân số
static fraction findMaxFraction(fraction* listF, int n) {

	fraction max = listF[0];
	for (int i = 0; i < n; i++) {
		max = findLarger(&max, &listF[i]);
	}

	return max;

}

//f. Viết hàm tính tổng các phân số trong dãy phân số
static fraction sumFraction(fraction* listF, int n) {

	fraction sum = { 0,1 };
	for (int i = 0; i < n; i++) {
		sum.tu = sum.tu * listF[i].mau + sum.mau * listF[i].tu;
		sum.mau = sum.mau * listF[i].mau;
	}

	return sum;

}

static void reducingFractions(fraction* f) {

	int a = abs(f->tu);
	int b = abs(f->mau);
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	f->tu /= a;
	f->mau /= a;

}


int main() {

	fraction* F = new fraction;
	fraction* listF = new fraction;
	int n = 0;
	// nhap phan so
	inputFraction(F);
	// xuat phan so
	outFraction(F);

	cout << "Nhap so luong phan so: ";
	do {
		cin >> n;
	} while (n <= 0);
	// nhap danh sach phan so
	inputListFraction(listF, n);
	// xuat danh sach phan so
	outListFraction(listF, n);

	fraction findMax = findMaxFraction(listF, n);
	cout << "Phan so lon nhat trong day la: "; outFraction(&findMax);

	fraction sum = sumFraction(listF, n);
	reducingFractions(&sum);
	cout << "Tong cac phan so = "; outFraction(&sum);

	return 0;
}
