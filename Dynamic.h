#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
private:
	int capacity;
	int size;
	int* array;
public:
	DynamicArray();
	~DynamicArray();
	void expand();
	void addAt(int index, int value);
	void deleteAt(int index);
	void addFront(int value);
	void deleteFront();
	void addBack(int value);
	void deleteBack();
	void display();
};
