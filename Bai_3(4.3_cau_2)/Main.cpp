#include <iostream>
#include <fstream> 
#include <vector> 
#include <cmath>
#include <string>

using namespace std;

//Read file
static vector<int> readFile(string filePath) {

	ifstream inFile(filePath);
	//Check file
	if (!inFile) {
		cout << "Cannot open file" << filePath;
		exit(1);
	}
	int n;
	inFile >> n;
	vector<int> array(n);
	for (int i = 0; i < n; i++) {
		inFile >> array[i];
	}
	inFile.close();
	return array;

}



int main() {

	string outFilePath = "outNguyenAm.txt";
	string inputString = "";
	string listNguyenAm = {};

	cout << "Nhap mot chuoi gi do di nao: ";

	getline(cin, inputString);  // Read a line into inputString

	ofstream outNguyenAm(outFilePath);
	for (char ch : inputString) {
		if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o' ||
			ch == 'A' || ch == 'I' || ch == 'U' || ch == 'E' || ch == 'O') {
			listNguyenAm.push_back(ch);
			listNguyenAm.push_back(' ');  // Add  space 
		}
	}

	outNguyenAm << listNguyenAm;

	outNguyenAm.close();

	return 0;
}
