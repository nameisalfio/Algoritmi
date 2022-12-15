#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

/*
	Problema di ottimizzazione --> 

	Se ho un problema di ottimizzazione vedo se la soluzione al problema più grande può essere ottenuta in funzione della risoluzione dei sottoproblemi

	Programmazione dinamica :

	-Sottostruttura ottima: la soluzione ottima al problema di partenza contiente una soluzione ottima ai sottoproblemi più piccoli

	Le soluzioni ai sottoproblemi vengono riportate man mano che salgo nella ricorsione per non doverle ricalcolare ogni volta(Ricorsione con memorizzazione)

	Siamo interessati a ricostruire la procedura che consente di arrivare al risultato ottimo e non solo a quest'ultimo.

	es. Prodotto riga x colonna di più matrici:

	Date A (q x r)	B (r x s) il costo del prodotto sara O(q x r x s)

	Quando si hanno più matrici da moltiplicare, considerando che il rapporto è associativo, si pone il problema della "parentesizzazione ottima", ovvero
	in che ordine moltiplicare le matrici al fine di ridurre il più possibile costo.


*/

int main()
{	
  vector <int> chain = vector<int>{ 5, 1, 3, 12 , 5,  50, 6 };
  vector<vector<int>> lookUpTable;	
  int operations= matrixChainMultiplyLookUp(chain, lookUpTable);	
  cout << "Number of operations:" << operations << endl;	
  cout << "LookUp Cost Table:" << endl;
  for (int i = 0; i < lookUpTable.size(); i++)
	{
		for (int j = 0; j < lookUpTable.at(i).size(); j++)
			cout << lookUpTable.at(i).at(j) << " ";
		cout << endl;
	}		
	printRecursiveParentheses(lookUpTable);
	cout << endl;
	printIterativeParentheses(lookUpTable);	
} 
