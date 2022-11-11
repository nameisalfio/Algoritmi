#ifndef RADIX_SORT_H
#define RADIX_SORT_H

/*
	Radix-Sort

	Il Radix Sort è un algoritmo di ordinamento per valori numerici interi con complessità computazionale Teta(d(n+k)), se la procedura 
	di ordinamento stabile che utilizza, ha costo Teta(n+k).

		- d è il numero di cifre dell'elemento massimo 
		- n è il numero di elementi nell'array
		- k sono i possibili valori che può assumere la cifra (in base 10 sono tutti i numeri in 0..9, quindi k=10)

	Per il corretto funzionamento di Radix Sort è essenziale che la procedura che riordina i numeri sulla base della i-esima cifra sia stabile, 
	infatti numeri diversi che hanno lo stesso valore per una cifra devono apparire esattamente nell'ordine in cui sono stati inseriti
	con l'ultima chiamata di ordinamento.
*/

void printArray(int A[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << "\n";
}

int getMax(int A[], int n){
	int max = A[0];
	for(int i=0; i<n; i++)
		if(A[i] > max)	max = A[i];
	return max;
}

void countingSort(int A[], int n, int place) {

  const int max = 10;	//ordino al massimo numeri da 0 a 9
  int B[n];
  int C[max]{0};

  for (int i = 0; i < n; i++)
    C[ (A[i]/place) % 10]++;	//nella i-esima posizione avrò tutti i numeri che hanno i nella place-esima cifra

  for (int i = 1; i < max; i++)		//nella i-esima posizione avrò tutti i numeri minori o uguali a C[i]
    C[i] += C[i - 1];

  for (int i = n - 1; i >= 0; i--) {		//colloco ordinatamente gli elementi
    B[C[(A[i] / place) % 10] - 1] = A[i];
    C[(A[i] / place) % 10]--;
  }

  for (int i = 0; i < n; i++)		//copio gli elementi nell'array finale
    A[i] = B[i];
}

void radixSort(int A[], int n) {

  int max = getMax(A, n);	//ricerco il massimo

  for (int place=1; max/place>0; place*=10)		// fino a che non conto un numero di cifre pari a quelle del massimo
  	countingSort(A, n, place);		// place = 1 - 10 - 100 - 1000 - ...
}

#endif