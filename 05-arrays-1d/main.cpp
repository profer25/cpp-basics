#include <iostream>

using namespace std;

struct Negatives {
	int first = -1;
	int last = -1;
};

double GetOddElemSum(double* arr, const int size);
void PrintArray(double* arr, const int size);
Negatives FindNegatives(double* arr, const int kArraySize);
double GetSumBtFirstLastNegatives(double* arr, Negatives negatives);
void SortArray(double* arr, double* sorted_array, const int kArraySize);

int main() {
	const int kArraySize = 10;
	double arr[kArraySize] = { 0, -0.1, 2, -3, 0.4, 5, 0.6, -7, 0.8, -9 };

	cout << "Initial array: \n";
	PrintArray(arr, kArraySize);

	cout << "\nThe sum of the elements of the array at odd positions: ";
	cout << GetOddElemSum(arr, kArraySize) << endl;

	Negatives negatives = FindNegatives(arr, kArraySize);
	if ((negatives.first > -1) && (negatives.first < negatives.last))
		cout << "\nSum = " << GetSumBtFirstLastNegatives(arr, negatives) << endl;
	else
		cout << "\nNo two negative elements were found.\n";

	cout << "\nSorted array: \n";
	double sorted_array[kArraySize];
	SortArray(arr, sorted_array, kArraySize);
	PrintArray(sorted_array, kArraySize);

	return 0;
}

void PrintArray(double* arr, const int kArraySize) {
	for (int i = 0; i < kArraySize; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

double GetOddElemSum(double* arr, const int kArraySize) {
	double sum = 0;
	for (int i = 1; i < kArraySize; i += 2)
		sum += arr[i];
	return sum;
}

Negatives FindNegatives(double* arr, const int kArraySize) {
	Negatives negatives;

	for (int i = 0; i < kArraySize; i++)
		if (arr[i] < 0)	{
			negatives.first = i;
			break;
		}

	for (int i = kArraySize - 1; i >= 0; i--)
		if (arr[i] < 0)	{
			negatives.last = i;
			break;
		}

	return negatives;
}

double GetSumBtFirstLastNegatives(double* arr, Negatives negatives) {
	double sum = 0;
	for (int i = negatives.first + 1; i < negatives.last; i++)
		sum += arr[i];
	return sum;
}

void SortArray(double* arr, double* sorted_array, const int kArraySize) {	
	int j = 0;
	for (int i = 0; i < kArraySize; i++)
		if (abs(arr[i]) >= 1) 
			sorted_array[j++] = arr[i];

	for (int i = j; i < kArraySize; i++)
		sorted_array[i] = 0.0;
}