#include "functions.h"

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