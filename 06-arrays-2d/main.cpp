#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void ReadData(int** matrix, ifstream& fin, int array_size);
void PrintMatrix(int** matrix, int array_size);
bool MultNonNegativeRows(int** matrix, int array_size, int& mult);
int MaxDiagonalSum(int** matrix, int array_size);

int main() {
	ifstream fin("matrix.txt");
	if (!fin.is_open()) {
		cout << "Can't open file: matrix.txt!\n";
		return 1;
	}

	int array_size;
	fin >> array_size;

	int** matrix = new int*[array_size];
	for (int i = 0; i < array_size; i++)
		matrix[i] = new int[array_size];
	ReadData(matrix, fin, array_size);

	cout << "Input data:\n";
	PrintMatrix(matrix, array_size);
	cout << endl;

	int mult;
	MultNonNegativeRows(matrix, array_size, mult);
	cout << "Multiplication = " << mult;
	cout << endl;

	cout << "\nThe maximum among the sums of diagonals: ";
	cout << MaxDiagonalSum(matrix, array_size);
	cout << endl;

	for (int i = 0; i < array_size; i++) delete[] matrix[i];
	delete[] matrix;

	return 0;
}

void ReadData(int** matrix, ifstream& fin, int array_size) {
	for (int i = 0; i < array_size; i++)
		for (int j = 0; j < array_size; j++)
			fin >> matrix[i][j];
	fin.close();
}

void PrintMatrix(int** matrix, int array_size) {
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++)
			cout << matrix[i][j] << "  ";
		cout << endl;
	}
}

bool MultNonNegativeRows(int** matrix, int array_size, int& mult) {
	mult = 1;
	bool negative_elements_in_matrix = false;
	for (int i = 0; i < array_size; i++) {
		int mult_row = 1;
		bool negative_elements_in_row = false;
		for (int j = 0; j < array_size; j++) {
			if (matrix[i][j] < 0) negative_elements_in_row = true;
			mult_row *= matrix[i][j];
		}
		if (!negative_elements_in_row) {
			mult *= mult_row;
			negative_elements_in_matrix = true;
		}
	}
	return negative_elements_in_matrix;
}

int MaxDiagonalSum(int** matrix, int array_size) {
	int sum = INT_MIN;
	for (int row = 0; row < array_size; row++) {
		int sum_below_main_diagonal = 0;
		int sum_above_main_diagonal = 0;
		int j = 0, i = row;
		while (i < array_size && j < array_size) {
			sum_below_main_diagonal += matrix[i][j];
			sum_above_main_diagonal += matrix[j++][i++];
		}
		sum = max(sum, max(sum_below_main_diagonal, sum_above_main_diagonal));
	}
	return sum;
}