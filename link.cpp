// link.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedListType.h"
using namespace std;
int main() {
	LinkedListType<int> list1, list2;
	int num;
	cout << " Enter numbers ending with -999" << endl;
	cin >> num;
	while (num != -999) {
		list1.insertLast(num);
		cin >> num;
	}
	cout << endl;
	cout << " List 1: ";
	list1.print();
	cout << endl;
	cout << " Length List 1: " << list1.length() << endl;
	int retfirst;
	list1.retrieveFirst(retfirst);
	cout << "list1.retrieveFirst; retfirst = " << retfirst << endl;
	int retlast;
	list1.retrieveLast(retlast);
	cout << "list1.retrieveLast; retlast = " << retlast << endl;
	list2 = list1;
	cout << "Line 16: List 2: ";
	list2.print();
	cout << endl;
	cout << "Line 17: Length List 2: " << list2.length() << endl;
	cout << "Line 18: Enter the number to be " << "deIeted: ";
	cin >> num;
	cout << endl;
	list2.deIeteNode(num);
	cout << "Line 22: After deleting the node, " << "List 2: " << endl;
	list2.print();
	cout << endl;
	cout << "Line 25: Length List 2: " << list2.length() << endl;
	system("pause");
	return 0;
}
