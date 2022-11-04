#ifndef COUNINTSORT_H
#define COUNINTSORT_H

void print(int vet[], int n){  
    cout << "\nArray: " << endl;
    for(int i=0; i<n; i++)
        cout << vet[i] << "\t";
    cout << endl;
}

int getMax(int A[], int n){
    int max = A[0];
    for(int i=1; i<n; i++)
        if(A[i] > max)  max = A[i];
    return max;
}
int getMin(int A[], int n){
    int min = A[0];
    for(int i=1; i<n; i++)
        if(A[i] < min)  min = A[i];
    return min;
}

void countingSort(int A[], int n){

	int min = getMin(A, n);
    int Max = getMax(A,n);
    int range = Max-min+1;

    int *C = new int[range]{0};
    int *B = new int[n];

    for(int i=0; i<n; i++)
    	C[A[i]-min] ++;

    for(int i=1; i<range; i++)
    	C[i] += C[i-1];

    for(int i=n-1; i>=0; i--)
   	{
   		B[C[A[i]-min]-1] = A[i];
   		C[A[i]-min] --;
   	}

   	for(int i=0; i<n; i++)
   		A[i] = B[i];

   	delete [] B;
   	delete [] C;
}

#endif