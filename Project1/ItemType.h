#pragma once
#include <iostream>
#include <vector>
#define START 0
#define AFTER_FIRST 1
#define AFTER_SECOND 2
#define AFTER_THIRD 3

using namespace std;

class ItemType
{
public:

	int size, m;
	vector<int> x, y;
	vector<int> a, b, c, d;
	vector<int> a_b, c_d, ac_bd;
	vector<int> pos_abcd, subOfPos;
	vector<int> vecRes1, vecRes2, vecRes3;
	vector<int> p0, p1;
	ItemType* next;
	int line; //0=start, 1=after_first, 2=after_second, 3 = after_third

	ItemType();
	ItemType(ItemType& other);
	~ItemType();


	void setLine(int _line);
	void SetItem(int _size, int _m, vector<int> _x, vector<int> _y,int _line);

	void operator=(const ItemType& other);

};

