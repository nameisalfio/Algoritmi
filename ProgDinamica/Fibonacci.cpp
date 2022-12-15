#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

int fib_ricorsivo(int n)
{
	if(n < 2)
		return n;
	else
		return fib_ricorsivo(n-2) + fib_ricorsivo(n-1);
}

int fib_dinamico(int n)
{
	int* vet = new int[n+1];

	vet[0] = 0;
	vet[1] = 1;

	for(int i=2; i<n+1; i++)
		vet[i] = vet[i-1] + vet[i-2];

	int ris = vet[n];	// problema di partenza
	delete vet;
	return ris;
}

int fib_dinamico_smart(int n)
{
	int vet [3];

	vet[0] = 0;
	vet[1] = 1;

	for(int i=2; i<n+1; i++)
	{
		vet[2] = vet[1] + vet[0];
		vet[0] = vet[1];
		vet[1] = vet[2];
	}

	return vet[2];
}

int main(){

	clock_t start = clock();

	int n;
	cout << "\nInserisci un intero: " << endl;
	cin >> n;

	cout << "\nVersione ricorsiva: " << fib_ricorsivo(n) << endl;
	cout << "\nVersione dinamica: " << fib_dinamico(n) << endl;
	cout << "\nVersione dinamica smart: " << fib_dinamico_smart(n) << endl;	

	clock_t end = clock();
	cout << "\nTempo di esecuzione totale = " << ((double)(end - start)) / CLOCKS_PER_SEC << " secondi" << endl;

} 

