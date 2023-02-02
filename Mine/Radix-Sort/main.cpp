#include<iostream>
using namespace std;

#include "radix_sort.h"

int main(){

	int arr[]{454, 87069, 3312, 5401, 1761, 346, 191, 958, 2022, 6498};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "\nArray is \n";
	printArray(arr, n);	
	radixSort(arr, n); 

	cout << "\nSorted array is \n";
	printArray(arr, n);
}