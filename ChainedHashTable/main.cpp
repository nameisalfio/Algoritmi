#include<iostream>
#include<list>
using namespace std;

#include "ChainHashing.h"

int main()
{
	
//Funzione hash realizzata tramite il metodo della divisione

	DivisionChainedHashTable<int>* hashDiv = new DivisionChainedHashTable<int> (7);

	int a[] = { 15, 11, 27, 8, 12 };	//Inserisco gli elementi nella tabella e la stampo
	for (int i = 0; i < 5; i++)
		hashDiv->insertKey(a[i]);
	hashDiv->printHashTable();
	cout << "Size: " << hashDiv->getSize() << endl;

	int pos = -1;
	int pos1= -1;
	hashDiv->searchKey(8, &pos, &pos1);
	cout << "\nKey 8 found at: "<<pos <<" " << pos1 << endl;

	cout<<"\nDeleting key 8"<<endl;
	hashDiv->deleteKey(8);
	hashDiv->printHashTable();
	cout << "Size: " << hashDiv->getSize() << endl;
	
	cout<<"\nDeleting key 12"<<endl;
	hashDiv->deleteKey(12);
	hashDiv->printHashTable();
	cout << "\nSize: " << hashDiv->getSize() << endl;

	cout << "Searching keys..." << endl;
	cout << "Key 27 :"<< hashDiv->searchKey(27) << endl;
	cout << "Key 899: "<< hashDiv->searchKey(899) << endl;	//not found


//Funzione hash realizzata tramite il metodo della moltiplicazione

	MultiplicationChainedHashTable<int> hashMul(5);	
	for (int i = 0; i < 5; i++)		// inserisco gli elenti nella tabella e la stampo
		hashMul.insertKey(a[i]);
	hashMul.printHashTable();
	cout << "Size: " << hashMul.getSize() << endl;

	cout<<"\nInserting key 56"<<endl;
	hashMul.insertKey(56);
	cout<<"\nDeleting key 12"<<endl;
	hashMul.deleteKey(12);
	hashMul.printHashTable();
	cout << "Size: " << hashMul.getSize() << endl;

}