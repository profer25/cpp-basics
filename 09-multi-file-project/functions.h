#include <iostream>

using namespace std;

struct Negatives
{
	int first = -1;
	int last = -1;
};

double GetOddElemSum(double* arr, const int size);
void PrintArray(double* arr, const int size);
Negatives FindNegatives(double* arr, const int kArraySize);
double GetSumBtFirstLastNegatives(double* arr, Negatives negatives);
void SortArray(double* arr, double* sorted_array, const int kArraySize);