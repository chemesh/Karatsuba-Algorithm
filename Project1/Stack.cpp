#pragma once
#include "Stack.h"

void Stack::push(ItemType& item)
{
	ItemType* newHead = new ItemType;
	*newHead = item;
	newHead->next = head;
	head = newHead;
}

ItemType& Stack::pop()
{
	if (IsEmpty())
	{
		cout << "error. stack is empty. closing program" << endl;
		exit(1);
	}
	
	ItemType& top = *head;
	head = head->next;
	top.next = nullptr;
	return top;
}

void Stack::MakeEmpty()
{
	ItemType* temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete[] temp;
	}
}

bool Stack::IsEmpty()
{
	return (head == nullptr);
}