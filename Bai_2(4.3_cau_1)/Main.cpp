#include <iostream>
#include <fstream> 
#include <vector> 
#include <cmath>

using namespace std;

//Check prime
static bool isPrime(int num) {

	if (num < 2) return false;
	for (int i = 2; i < sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;

}

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

static void outVector(vector<int> arr, int n) {

	for (int i = 0; i < n; i++) {

		cout << arr[i] << "\t";

	}

}




int main() {

	string filePath = "Data.txt";
	string outFilePath = "OutPrime.txt";
	vector<int> arrPrime = {};

	// read file
	vector<int> arr = readFile(filePath);

	// print file to screen
	outVector(arr, arr.size());

	//check prime
	for (int i = 0; i < arr.size(); i++) {
		if (isPrime(arr[i])) {
			arrPrime.push_back(arr[i]);
		}
	}
	// write prime to file
	ofstream outPrimeFile("Data_Prime.txt");
	for (int num : arrPrime) {
		outPrimeFile << num << "\n";
	}

		return 0;
}
