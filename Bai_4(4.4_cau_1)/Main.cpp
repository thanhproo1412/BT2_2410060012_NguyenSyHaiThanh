#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

typedef struct matrix {
	int d;
	int c;
	int** data;
}Matrix;

static int** createRandomMatrix(int d, int c) {

	int** matrix = new int* [d];
	for (int i = 0; i < d; i++) {
		matrix[i] = new int[c];
	}
	srand(time(0));
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {

			matrix[i][j] = rand() % 100; // random 0 -> 100

		}
	}

	return matrix;
}

static void writeMatrixToFile(int** matrix, int d, int c, string fileName) {

	ofstream outMatrixFile(fileName);
	if (!outMatrixFile) {
		cout << "Something went wrong, can't open file" << endl;
	}
	outMatrixFile << d << " " << c << endl;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			outMatrixFile << matrix[i][j] << ' ';
		}
		outMatrixFile << endl;
	}
	outMatrixFile.close(); // Close file 
}

static Matrix readMatrixFromFile(string filePath) {
	Matrix matrix{ 0,0, nullptr };

	ifstream inFile(filePath);
	if (!inFile) {
		cout << "Something went wrong, can't open file" << endl;
		return matrix;
	}
	inFile >> matrix.d >> matrix.c;

	matrix.data = new int* [matrix.d];
	for (int i = 0; i < matrix.d; i++) {
		matrix.data[i] = new int[matrix.c];
	}

	for (int i = 0; i < matrix.d; i++) {
		for (int j = 0; j < matrix.c; j++) {
			inFile >> matrix.data[i][j];
		}
	}
	inFile.close();

	return matrix;
}

static void printMatrix(int** matrix, int d, int c) {

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}

}



int main() {

	Matrix matrix{ 0,0, nullptr };
	matrix.d = 5;
	matrix.c = 6;
	const string filePath = "test.inp";

	matrix.data = createRandomMatrix(matrix.d, matrix.c);
	Matrix matrixFromFile = readMatrixFromFile(filePath);

	writeMatrixToFile(matrix.data, matrix.d, matrix.c, filePath);

	printMatrix(matrixFromFile.data, matrixFromFile.d, matrixFromFile.c);




	// Clean up memory
	for (int i = 0; i < matrix.d; i++) {
		delete[] matrix.data[i];
	}
	delete[] matrix.data;

	// Clean up memory
	for (int i = 0; i < matrixFromFile.d; i++) {
		delete[] matrixFromFile.data[i];
	}
	delete[] matrixFromFile.data;

	return 0;
}