#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include <vector>

using namespace std;

typedef struct sinhvien {
	char maSV[50];
	char tenSV[50];
	char lop[50];
	float dtk;
}SV;

static vector<SV> inputListSV() {

	int n = 0;
	cout << "Nhap so luong sinh vien" << endl;
	cin >> n;
	cin.ignore(); // Bỏ qua kí tự newline
	vector<SV> listSV = {};
	for (int i = 0; i < n; i++) {
		SV student;
		cout << "Nhap mssv so " << i + 1 << ": ";
		cin >> student.maSV;
		cout << "Nhap ten sinh ven so " << i + 1 << ": ";
		cin >> student.tenSV;
		cout << "Nhap lop sinh vien " << i + 1 << ": ";
		cin >> student.lop;
		cout << "Nhap diem tong ket " << i + 1 << ": ";
		cin >> student.dtk;
		cin.ignore(); // Bỏ qua kí tự newline
		listSV.push_back(student);
	}

	return listSV;
}

static void saveDSSV(vector<SV> listSV, string filePath) {
	ofstream outFile(filePath);
	if (!outFile) {
		cout << "Can't save file";
		return;
	}
	for (int i = 0; i < listSV.size(); i++) {
		outFile << listSV[i].maSV << " ";
		outFile << listSV[i].tenSV << " ";
		outFile << listSV[i].lop << " ";
		outFile << listSV[i].dtk << " ";
		outFile << endl;
	}
	outFile.close();

}

static vector<SV> readListSV(string filePath) {

	vector<SV> listSV = {};
	cout << "start read file" << endl;
	ifstream inFile(filePath);
	if (!inFile) {
		cout << "Can't open the file!" << endl;
		return listSV;
	}
	SV student = {};
	while (inFile >> student.maSV >> student.tenSV >> student.lop >> student.dtk) {
		listSV.push_back(student);
	}
	inFile.close();

	return listSV;
}

static void printListSV(vector<SV> listSV) {
	cout << "Xuat DSSV:" << endl;
	for (const auto& student : listSV) {
		cout << "MSSV: " << student.maSV << " ";
		cout << "Ten sv: " << student.maSV << " ";
		cout << "lop: " << student.maSV << " ";
		cout << "diem tong ket: " << student.maSV << " " << endl;
	}
}


int main() {

	const string filePath = "DSSV.txt";

	// input dssv
	vector<SV> listSV = inputListSV();
	//save dssv to filePath
	saveDSSV(listSV, filePath);
	// read dssv
	vector<SV> listSVFromFile = readListSV(filePath);
	listSVFromFile = readListSV(filePath);
	// print dssv
	printListSV(listSVFromFile);


	return 0;
}