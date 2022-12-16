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
		list.insertHead(val);
	}
	is.close();
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
	ofstream os("toAdd.txt");
	while(idx++ < val)
	{
		x = rand() % 100;
		if(list.search(x) == nullptr)
		{	
			cout << "Casualizzatore : " << x << endl;
			list.insertHead(x);
			string str = to_string(x);
			os << str.append("\n");
		}
	}
	os.close();
	//cout << list << endl;
}