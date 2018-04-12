#include "stdafx.h"

#include <iostream>
#include <conio.h>

#include "MyDeque.h"

using namespace std;

int main()
{
	MyDeque d;
	int action = 1;
	int value;
	cout << "Choose an action:" << endl
		 << "0.Exit" << endl
		 << "1.Push front" << endl
		 << "2.Push back" << endl
		 << "3.Pop front" << endl
		 << "4.Pop back" << endl
		 << "5.Show deque" << endl
		 << "6.Sort it" << endl
		 << "7.Sort 10 random elements" << endl
		 << "8.Sort 100 random elements" << endl
		 << "9.Sort 1000 random elements" << endl
		 << "10.Sort 10000 random elements" << endl;

	while (action)
	{
	cin >> action;
	switch (action)
	{
		case 0:
			break;
		case 1:
			cout << "\nEnter value: ";
			cin >> value;
			d.pushFront(value);
			break;
		case 2:
			cout << "\nEnter value: ";
			cin >> value;
			d.pushFront(value);
			break;
		case 3:
			cout << d.popFront();
			break;
		case 4:
			cout << d.popBack();
			break;
		case 5:
			d.showIt();
			break;
		case 6:
			d.bSort();
			break;
		case 7:
			trySort(10, d);
			break;
		case 8:
			trySort(100, d);
			break;
		case 9:
			trySort(1000, d);
			break;
		case 10:
			trySort(10000, d);
			break;
		default:
			cout << " Default";
			break;
		}
	}
	d.clear();
	_getch();
	return 0;
}
