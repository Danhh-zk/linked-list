#pragma once

#include <iostream>
#include <cassert>
#include<assert.h>
using namespace std;
template <class Type>
struct nodeType {
	Type info;
	nodeType<Type>* link;
};
template<class Type>
class LinkedListType {
private:
	nodeType<Type>* first;
	nodeType<Type>* last;
	int count;
public:
	void initializeList();
	bool isEmptyList();
	bool isFullList();
	void print();
	int length();
	void destroyList();
	void retrieveFirst(Type& firstElement);
	void retrieveLast(Type& lastElement);
	void search(const Type& searchItem);
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deIeteNode(const Type& deleteItem);
	LinkedListType();
	~LinkedListType();
	LinkedListType(const LinkedListType<Type>& otherList);
	const LinkedListType<Type>& operator= (const LinkedListType<Type>&);
};
template<class Type>
bool LinkedListType<Type>::isEmptyList()
{
	return(first == NULL);
}
template<class Type>
bool LinkedListType<Type>::isFullList()
{
	return false;
}
template<class Type>
LinkedListType<Type>::LinkedListType()
{
	first = NULL;
	last = NULL;
	count = 0;
}
template<class Type>
void LinkedListType<Type>::destroyList()
{
	nodeType<Type>* temp;
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}
template<class Type>
void LinkedListType<Type>::initializeList()
{
	destroyList();
}
template<class Type>
void LinkedListType<Type>::print()
{
	nodeType<Type>* current;
	current = first;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
}
template<class Type>
int LinkedListType<Type>::length()
{
	int count = 0;
	nodeType<Type>* current;
	current = first;
	while (current != NULL)
	{
		count++;
		current = current->link;
	}
	return count;
}
template<class Type>
void LinkedListType<Type>::retrieveFirst(Type& firstElement)
{
	assert(first != NULL);
	firstElement = first->info;
}
template<class Type>
void LinkedListType<Type>::retrieveLast(Type& lastElement)
{
	assert(last != NULL);
	lastElement = last->info;
}
template<class Type>
void LinkedListType<Type>::search(const Type& item)
{
	nodeType<Type>* current;
	bool found;
	if (first == NULL)
		cout << "Cannot search an empty list. " << endl;
	else
	{
		current = first;
		found = false;
		while (!found && current != NULL)
			if (current->info == item)
				found = true;
			else
				current = current->link;
		if (found)
			cout << "Item is found in the list." << endl;
		else
			cout << "Item is not in the list." << endl;
	}
}
template<class Type>
void LinkedListType<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type>* newNode;
	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->Iink = first;
	first = newNode;
	if (last == NULL)
		last = newNode;
}
template<class Type>
void LinkedListType<Type>::insertLast(const Type& newItem)
{
	nodeType<Type>* newNode;
	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = NULL;
	if (first == NULL)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->link = newNode;
		last = newNode;
	}
}
template<class Type>
void LinkedListType<Type>::deIeteNode(const Type& deleteItem) {
	nodeType<Type>* current;
	nodeType<Type>* trailCurrent;
	bool found;
	if (first == NULL)
		cout << "Can not delete from an empty list.\n";
	else
	{
		if (first->info == deleteItem)
		{
			current = first;
			first = first->link;
			if (first == NULL)
				last = NULL;
			delete current;
		}
		else
		{
			found = false;
			trailCurrent = first;
			current = first->link;
			while ((!found) && (current != NULL))
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}
			if (found)
			{
				trailCurrent->link = current->link;
				if (last == current)
					delete current;
			}
			else
				cout << "Item to be deleted is not in the list." << endl;
		}
	}
}
template<class Type>
LinkedListType<Type>::~LinkedListType()
{
	nodeType<Type>* temp;
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
}
template<class Type>
LinkedListType<Type>::LinkedListType(const LinkedListType<Type>& otherList)
{
	nodeType<Type>* newNode;
	nodeType<Type>* current;
	if (otherList.first == NULL)
	{
		first = NULL;
		last = NULL;
	}
	else
	{
		current = otherList.first;
		first = new nodeType<Type>;
		first->info = current->info;
		first->link = NULL;
		last = first;
		current = current->link;
		while (current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->Iink = NULL;
			last->Iink = newNode;
			last = newNode;
			current = current->link;
		}
	}
}
template<class Type>
const LinkedListType<Type>& LinkedListType<Type>::operator=(const
	LinkedListType<Type>& otherList)
{
	nodeType<Type>* newNode;
	nodeType<Type>* current;
	if (this != &otherList)
	{
		if (first != NULL)
			destroyList();
		if (otherList.first == NULL)
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			current = otherList.first;
			first = new nodeType<Type>;
			first->info = current->info;
			first->link = NULL;
			last = first;
			current = current->link;
			while (current != NULL)
			{
				newNode = new nodeType<Type>;
				newNode->info = current->info;
				newNode->link = NULL;
				last->link = newNode;
				last = newNode;
				current = current->link;
			}
		}
	}
	return *this;
}


