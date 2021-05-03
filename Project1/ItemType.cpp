#pragma once
#include "ItemType.h"

ItemType::ItemType() :size(1), next(nullptr), line(START), m(0) {}

ItemType::ItemType(ItemType& other)
{
	size = other.size;
	m = other.m;
	x = other.x;
	y = other.y;
	next = other.next;
	line = other.line;
	vecRes1 = other.vecRes1;
	vecRes2 = other.vecRes2;
	vecRes3 = other.vecRes3;
}

ItemType::~ItemType() { delete[] next; }

void ItemType::setLine(int _line) { line = _line; }
void ItemType::SetItem(int _size, int _m, vector<int> _x, vector<int> _y, int _line)
{
	size = _size;
	m = _m;
	x = _x;
	y = _y;
	line = _line;
	//next = _next;
	//vecRes1 = _vecRes1;
	//vecRes2 = _vecRes2;
	//vecRes3 = _vecRes3;
}

void ItemType::operator=(const ItemType& other)
{
	size = other.size;
	m = other.m;
	x = other.x;
	y = other.y;
	next = other.next;
	line = other.line;
	vecRes1 = other.vecRes1;
	vecRes2 = other.vecRes2;
	vecRes3 = other.vecRes3;
	a = other.a;
	b = other.b;
	c = other.c;
	d = other.d;
	//ac = other.ac;
	//bd = other.bd;
	a_b = other.a_b;
	c_d = other.c_d;
	ac_bd = other.ac_bd;
	pos_abcd = other.pos_abcd;
	subOfPos = other.subOfPos;
	
}