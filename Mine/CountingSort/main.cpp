#include<iostream>
using namespace std;

#include "countingSort.h"

int main(){

	int arr[]{7, 8, 0, 9, 8, 7, 0, 9, 8, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	int range = 10; //max-min+1

	cout << "\nArray is \n";
	print(arr, n);	
	countingSort(arr, n); 

	cout << "\nSorted array is \n";
	print(arr, n);
}