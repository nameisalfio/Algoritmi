#ifndef HEAP_H
#define	HEAP_H

template<class T>
class PriorityQueue
{
 public:
	virtual T* extract() = 0;

  virtual PriorityQueue<T>* enqueue(T x) = 0;	

	virtual double compare(T* a, T* b) = 0;

	virtual void printKey(int i) const = 0;
};

template<class T>
class BinaryHeap : public PriorityQueue<T>
{
	// Attributi
	T** queue;	//coda
	int heapsize;	//# elementi dello heap
	int queueLength;	//dimensione della coda

	// Metodi
	int left(int i){return 2*i;}	// i << 1

	int right(int i){return 2*i+1;}	// (i << 1) | 1

	int parent(int i){return i/2;}	// i >> 1
 
	void swap(int i, int j)
	{
		T* temp = queue[i];
		queue[i] = queue[j];
		queue[j]  = temp;
	}

	void heapify(int index)		//sposta la chiave verso il basso
	{
		int m = index;
		while(index <= heapsize/2)	//fino all'ultimo nodo che ha figli
		{
			int l = left(index);
			int r = right(index);

			if(l <= heapsize && compare(queue[m], queue[l]) < 0)	//finchè non viene rispettata la relazione di ordinamento dai figli
				m = l;
			if(r <= heapsize && compare(queue[m], queue[r]) < 0)	//finchè non viene rispettata la relazione di ordinamento dai figli
				m = r;

			if(m == index)
				break;

			swap(index, m);
			index = m;
		}
	}

	void recursiveHeapify(int i)
	{
		if (i > heapsize/2) 
			return;

		int l = left(i);
		int r = right(i);
		int m = i;

		if (l <= heapsize && compare(queue[m], queue[l]) < 0)
			m = l;

		if (r <= heapsize && compare(queue[m], queue[r]) < 0)
			m = r;

		if (m == i)
			return;

		swap(i, m);			
		recursiveHeapify(m);
	}
 public:

	BinaryHeap(int size)
	{
	  queue = new T * [size+1];
	  queueLength = size+1;
	  heapsize = 0;
  }

	BinaryHeap(T** vet, int size)
	{
		queue = vet;
		queueLength = size;
		heapsize = size-1;
	}

	virtual double compare(T* a, T* b) = 0;

	virtual void printKey(int i) const = 0;	

	void buildHeap()
	{		  
		for (int i = heapsize / 2; i > 0; i--)
			heapify(i);
	}

	T* extract()
	{
		if (heapsize == 0) 
			return NULL;
			
		swap(1, heapsize);
		heapsize--;
		heapify(1);
		return queue[heapsize + 1];
	}

	void modify(int i, T k)		//	increase(decrease)
  	{
		if (i<1 || i>heapsize)	// out of range
			return;

		if (compare(queue[i], &k) >= 0)	// se non viola la proprietà di ordinamento parziale
			return;

		delete queue[i];
		queue[i] = new T(k);
		while (i > 1 && compare(queue[i], queue[parent(i)]) > 0)
		{
			swap(i, parent(i));
	    	i = parent(i);
		}		
	}

	BinaryHeap<T>* enqueue(T x)		//insert-key
	{
		if(heapsize +1 == queueLength)
			return this;

		heapsize++;
		queue[heapsize] = new T(x);
		int i = heapsize;
		while (i > 1 && compare(queue[i], queue[parent(i)]) > 0)
		{
			swap(i, parent(i));
			i = parent(i);
		}
		return this;
	}

	void sort()		// heap-sort
	{	 
		int n = heapsize;
		for (int i=0; i<n; i++) 
			extract();
		heapsize = n;	//ripristino heapsize ma non è una heap valida in quanto tutti gli elementi sono ordinati
	}

	//Additionals

	T** getPriorityQueue() const {return queue;}

	void print() const
	{
		for (int i = 1; i <= this->size(); i++)
			printKey(i);
		cout << endl;
	}
  
	int size() const {return heapsize;}
};

//	Max-heap
template<class T>
class MaxBinaryHeap : public BinaryHeap<T>
{
 public:
	MaxBinaryHeap(int size) : BinaryHeap<T>(size){}

	MaxBinaryHeap(T** A, int size) : BinaryHeap<T>(A, size){}

	virtual double compare(T* a, T* b) = 0;	

	virtual void printKey(int i) const = 0;

	T* extractMax(){return BinaryHeap<T>::extract();}

	void increaseKey(int i, T k){return BinaryHeap<T>::modify(i, k);}
};

template <class T> 
class MaxHeap : public MaxBinaryHeap<T>
{
 public:
 	MaxHeap(int size) : MaxBinaryHeap<T>(size) {}

	MaxHeap(T** A, int size) : MaxBinaryHeap<T>(A, size) {}	

	double compare(T* a, T* b){return (*a) - (*b);}		//true solo se "a > b"

	void printKey(int i) const {cout << *(this->getPriorityQueue())[i] << " ";}
};

// Min-Heap
template<class T>
class MinBinaryHeap : public BinaryHeap<T>
{
 public:
	MinBinaryHeap(int size) : BinaryHeap<T>(size){}

	MinBinaryHeap(T** A, int size) : BinaryHeap<T>(A, size){}

	virtual double compare(T* a, T* b) = 0;	

	virtual void printKey(int i) const = 0;

	T* extractMin(){return BinaryHeap<T>::extract();}

	void decreaseKey(int i, T k){return BinaryHeap<T>::modify(i, k);}
};

template <class T> 
class MinHeap : public MinBinaryHeap<T>
{
  public:
	MinHeap(int size) : MinBinaryHeap<T>(size) {}

	MinHeap(T** A, int size) : MinBinaryHeap<T>(A, size) {}

	double compare(T* a, T* b){return  (*b) - (*a);}	// true solo se "a < b"

	void printKey(int i) const {cout << *(this->getPriorityQueue())[i] << " ";}
};

#endif