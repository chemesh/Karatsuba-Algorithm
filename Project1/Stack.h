#pragma once
#include <iostream>
#include "ItemType.h"

using namespace std;

class Stack
{
private:
	ItemType* head;

public:
	Stack() : head(nullptr) {}
	Stack(ItemType* _head) : head(_head) {}
	~Stack() { MakeEmpty(); }

	void push(ItemType&);
	ItemType& pop();
	void MakeEmpty();
	bool IsEmpty();


};