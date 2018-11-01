#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

template <class T>
void ReadData(T** matrix, ifstream& fin, int array_size);

template <class T>
void PrintMatrix(T** matrix, int array_size);

template <class T>
bool MultNonNegativeRows(T** matrix, int array_size, T& mult);

template <class T>
T MaxDiagonalSum(T** matrix, int array_size);

template <class T>
int Execute(string file_name);

int main() {

	string option;
selection:
	cout << "Select the data type (0 - integer, 1 - double, 2 - float): ";
	cin >> option;
	if (option == "0") {
		Execute<int>("integer.txt");
	}
	else
		if (option == "1") {
			Execute<double>("double.txt");
		}
		else
			if (option == "2") {
				Execute<float>("float.txt");
			}
			else {
				cout << "Wrong input!\n\n";
				goto selection;
			}

	return 0;
}

template <class T>
int Execute(string file_name) {
	ifstream fin(file_name);
	if (!fin.is_open()) {
		cout << "Can't open file: " << file_name << "!\n";
		return 1;
	}

	int array_size;
	fin >> array_size;

	T** matrix = new T*[array_size];
	for (int i = 0; i < array_size; i++)
		matrix[i] = new T[array_size];
	ReadData(matrix, fin, array_size);

	cout << "Input data:\n";
	PrintMatrix(matrix, array_size);
	cout << endl;

	T mult;
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

template <class T>
void ReadData(T** matrix, ifstream& fin, int array_size) {
	for (int i = 0; i < array_size; i++)
		for (int j = 0; j < array_size; j++)
			fin >> matrix[i][j];
	fin.close();
}

template <class T>
void PrintMatrix(T** matrix, int array_size) {
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++)
			cout << matrix[i][j] << "  ";
		cout << endl;
	}
}

template <class T>
bool MultNonNegativeRows(T** matrix, int array_size, T& mult) {
	mult = 1;
	bool negative_elements_in_matrix = false;
	for (int i = 0; i < array_size; i++) {
		T mult_row = 1;
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

template <class T>
T MaxDiagonalSum(T** matrix, int array_size) {
	// Main diagonal.
	T sum = 0;
	for (int i = 0; i < array_size; i++)
		sum += matrix[i][i];

	// Remaining diagonals.
	for (int row = 1; row < array_size; row++) {
		T sum_below_main_diagonal = 0;
		T sum_above_main_diagonal = 0;
		int j = 0, i = row;
		while (i < array_size && j < array_size) {
			sum_below_main_diagonal += matrix[i][j];
			sum_above_main_diagonal += matrix[j++][i++];
		}
		sum = max(sum, max(sum_below_main_diagonal, sum_above_main_diagonal));
	}
	return sum;
}