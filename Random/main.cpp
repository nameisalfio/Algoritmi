#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#include "list.h"

void init(List<int>& list)
{
	ifstream is("file.txt");
	int val = 0;
	while(is.good())
	{
		is >> val;

		if(is.good())
			list.insertTail(val);

	}
	is.close();
}

void preserv(List<int>& list)
{
	ofstream os("file.txt");
	string str = "";
	Node<int>* ptr = list.getHead();
	while(ptr)
	{
		str = to_string(ptr->getVal());
		os << str.append("\n");
		ptr = ptr->getNext();
	}
}

int main()
{
	srand(time(NULL));

	List<int> list;
	int idx, x = 0; 
	unsigned short val = 0;
	string _x = "";
	bool isPresent = false;
	init(list);	

	cout << "Input : " << endl;
	cin >> val;
	while(idx < val)
	{
		x = rand() % 100;
		if(list.search(x) == nullptr)
		{	
			idx ++;
			cout << "Casualizzatore : " << x << endl;
			list.insertTail(x);
		}
	}
	cout << list << endl;
	preserv(list);
}