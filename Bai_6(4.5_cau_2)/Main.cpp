#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef struct product {
	char mh[5];
	int sl;
	float dg;
	float st;
}product;

static vector<product> inputProduct() {

	vector<product> listProduct = {};
	int n;
	cout << "Nhap so luong khach hang: ";
	cin >> n;
	product prod = {};
	for (int i = 0; i < n; i++) {

		cout << "Nhap ma hang: ";
		cin >> prod.mh;
		cout << "Nhap so luong: ";
		cin >> prod.sl;
		cout << "Nhap don gia: ";
		cin >> prod.dg;
		prod.st = prod.sl * prod.dg;

		listProduct.push_back(prod);
	}

	return listProduct;
}

static void saveListProduct(const vector<product>& listprod, const string& filePath) {

	ofstream outFile(filePath);
	if (!outFile) {
		cout << "can't open file";
		return;
	}
	for (const product& prod : listprod) {

		outFile << prod.mh << " " << prod.sl << " " << prod.dg << " " << prod.st << endl;

	}
	outFile.close();
	cout << "Data saved successful to " << filePath << endl;

}

static vector<product> loadListProductFromFile(string filePath) {

	vector<product> listProduct;

	ifstream inFile(filePath);
	if (!inFile) {
		cout << "Can't open file";
		return {};
	}
	product prod = {};
	while (inFile >> prod.mh >> prod.sl >> prod.dg >> prod.st) {
		listProduct.push_back(prod);
	}
	inFile.close();
	cout << "Data loaded " << filePath << " successful" << endl;
	return listProduct;

}

static void printListproduct(const vector<product>& listprod) {

	for (const product& prod : listprod) {
		cout << "Ma hang: " << prod.mh
			<< ", So luong: " << prod.sl
			<< ", Don gia: " << prod.dg
			<< ", Thanh tien: " << prod.st << endl;
	}

}



int main() {

	// file name
	const string filePath = "DSHH.txt";

	// delecrale variable and input prod
	vector<product> listProd = inputProduct();

	// save list prod to filePath
	saveListProduct(listProd, filePath);

	// read list prod from filePath
	vector<product> listProdFromFile = loadListProductFromFile(filePath);

	// print list to screen
	printListproduct(listProdFromFile);


	return 0;
}