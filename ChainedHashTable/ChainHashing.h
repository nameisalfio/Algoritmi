#ifndef CHAINHASHING_H 
#define CHAINHASHING_H

template<class T>
class HashTable{
public:	     	
	virtual HashTable<T>* insertKey(T x)=0;
	virtual HashTable<T>* deleteKey(T key)=0;		
	virtual int searchKey(T key) = 0;	
};

template<class T>
class ChainedHashTable : public HashTable<T>{

private:
	list<T>* table;
	int slots;    // Number of slots (m)
	int size;	//n

protected:
	list<T>* getTable(){return this->table;}

public:
	ChainedHashTable<T>(int x)	// x slot 
	{
		this->slots = x;
		table = new list<T>[slots];
		size = 0;		
	}

	virtual int computeHashFunction(T x) = 0;

	int getSlotNumber(){return slots;}

	int getSize(){return size;}

	void printHashTable()
	{
		cout << endl;
		for (int i = 0; i < this->getSlotNumber(); i++)
		{
			cout << i;
			for (auto x : table[i])
				cout << " --> [" << x << "]";
			cout << endl;
		}
	}

	int searchKey(T key)
	{
		int index = computeHashFunction(key);	// index = h(k)
		typename list<T>::iterator i;	// iterator è un puntatore ad oggetto dinamico
		for (i = table[index].begin(); i != table[index].end(); i++)	// begin() torna il puntatore ad inizio lista
		{
			if (*i == key)
				return index;
		}
		return -1;	
	}

	// pos 1 -> posizione della sottolista (es. 3 per la terza sottolista dell'array)
	// pos 2 -> posizione della chiave all'interno della sottolista
	void searchKey(T key, int* pos1, int* pos2)	// per cancellare all'interno di una sottolista 
	{
		*pos1 = computeHashFunction(key);
		typename list<T>::iterator i;
		for (i = table[*pos1].begin(); i != table[*pos1].end(); i++)
		{
			if (*i == key)
			{				
				*pos2 = (int) distance(table[*pos1].begin(), i);	// cast a int necessario perchè distance torna un T
				return;
			}
		}		 
		*pos2 = -1;
	}

	ChainedHashTable<T>* insertKey(T key)
	{
		int index, pos2;		
		searchKey(key, &index, &pos2);		
		if (pos2 == -1)	// se non ho trovato la chiave
		{			
			table[index].push_front(key);	// insertHead()
			size++;
		}
		return this;
	}

	ChainedHashTable<T>* deleteKey(T key)
	{		
		int pos1 = -1;	// indice della sottolista
		int pos2 = -1;	// distanza della chiave dalla testa della pos1-esima lista nell'array table
		searchKey(key, &pos1, &pos2);
		if (pos2 != -1)	// se non ho trovato la chiave
		{
			typename list<T>::iterator i = table[pos1].begin();
			advance(i, pos2);	// pos2 incrementi a partire da i
			table[pos1].erase(i);
			size--;
		}
		return this;
	}
};

template <class T> 
class DivisionChainedHashTable : public ChainedHashTable<T>
{

public:
	DivisionChainedHashTable<T>(int edge_number) : ChainedHashTable<T>(edge_number) {}

private:
	int computeHashFunction(T x) 
	{
		int h = ((int)x % this->getSlotNumber());
		return h;
	}
};


template <class T> 
class MultiplicationChainedHashTable : public ChainedHashTable<T>
{
public:
	MultiplicationChainedHashTable(int edge_number) : ChainedHashTable<T>(edge_number){c = 0.7;}

private:
	double c;
	int computeHashFunction(T x) 
	{
		double y = x * c;
		double a = y - (int)y;
		int h = (int)(a * this->getSlotNumber());
		return h;
	}
};

#endif
