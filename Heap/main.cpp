#include<iostream>
using namespace std;

#include "Heap.h"

int main()
{
    cout << "Max Heap:\n----------------------\n" << endl;
    MaxHeap<int>* h = new MaxHeap<int>(100);    // primo costruttore
    h->enqueue(6)->enqueue(9)->enqueue(2)->enqueue(7)->enqueue(12);

    cout << "The queue is:" << endl;
    h->print();

    cout << "\nThe max is:\t" << *(h->extractMax()) << endl;

    cout << "\nThe queue after the extact is:" << endl;
    h->print(); 

    cout << "\nAdd elements(4 - 1 - 5):" << endl;
    h->enqueue(4)->enqueue(1)->enqueue(5);
    h->print();

    cout << "\nIncrease key with index 6 to 8:" << endl;
    h->increaseKey(5, 8);   
    h->print();

    cout << "\nSorting:" << endl;
    h->sort();
    h->print();

    cout << endl;

    int n = 10;
    int** V = new int*[n];
    for(int i=1; i<n; i++)
        V[i] = new int(rand()%n);     // creo un array di 10 puntatori a un int casuale

    cout << "Min Heap:\n----------------------\n" << endl;
    MinHeap<int>* h2 = new MinHeap<int>(V, n);      // secondo costruttore

    cout << "The initial array is:" << endl;
    h2->print();

    cout << "\n..building the heap..\n" << endl;
    h2->buildHeap();

    cout << "The heap is:" << endl;
    h2->print();

    cout << "\nSorting:" << endl;
    h2->sort();
    h2->print();

}