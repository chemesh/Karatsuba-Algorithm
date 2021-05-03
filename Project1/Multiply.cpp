
#include "Multiply.h"
#include <stdio.h>

namespace DSP1
{

	Multiply::Multiply(const unsigned int& _n) :n(_n)
	{
		X = new int[n];
		Y = new int[n];
		product = new int[2 * n];
	}

	Multiply::Multiply() : Multiply(1)
	{}

	Multiply::~Multiply()
	{
		delete[] X;
		delete[] Y;
		delete[] product;
	}

	bool Multiply::set_n(const unsigned int& _n)
	{
		this->n = n;
		resizeX(n);
		resizeY(n);
		resizeProduct(n);
		return true;
	}

	void Multiply::resizeX(int n)
	{
		int i = 0;
		int* temp = new int[n];
		while (X + i != nullptr && i < n);
		{
			temp[i] = X[i];
			i++;
		}
		delete[] X;
		X = temp;
	}

	void Multiply::resizeY(int n)
	{
		int i = 0;
		int* temp = new int[n];
		while (Y + i != nullptr && i < n);
		{
			temp[i] = Y[i];
			i++;
		}
		delete[] Y;
		Y = temp;
	}

	void Multiply::resizeProduct(int n)
	{
		int i = 0;
		int* temp = new int[2*n];
		while (product + i != nullptr && i < 2*n);
		{
			temp[i] = product[i];
			i++;
		}
		delete[] product;
		product = temp;
	}

	bool Multiply::set_X(char* str)
	{
		int i = 0, len = 0;
		while (str[i] != 0)
		{
			len++;
			i++;
		}
		if (len != n )
		{
			return false;
		}

		for (int i = 0; i < n; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				X[i] = str[i] - '0';
				vecX.push_back(X[i]);
			
			}
			else
			{
				return false;
			}
		}
		return true;
	}
						 
	bool Multiply::set_Y(char* str)
	{
		int i = 0, len = 0;
		while (str[i] != 0)
		{
			len++;
			i++;
		}
		if (len != n)
		{
			return false;
		}

		for (int i = 0; i < n; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				Y[i] = str[i] - '0';
				vecY.push_back(Y[i]);
			}
			else
			{

				return false;
			}
		}
		return true;
	}

	bool Multiply::set_product()
	{
		for (int i = 0; i < 2 * n; i++)
		{ 
			product[i] = 0;
			vecProd.push_back(0);
		}
		return true;
	}
	
	const int* Multiply::get_product()const
	{
		return product;
	}



	void Multiply::print_product()
	{
		int i = 0;
		while (product[i] == 0 && i<2*n-1)
			i++;

		cout << "Long multiplication : x * y = ";
		for (i; i < 2* n; i++)
		{
			cout << product[i];
		}
		cout << endl;
	}

	void Multiply::print_vecProd(int flag)
	{
		

		while (vecProd.at(0)==0 && vecProd.size() != 1)
		{
			vecProd.erase(vecProd.begin());
		}

		if (flag == 1)
		{
			cout << "Karatsuba (recursive): X * Y = ";
		}

		else
		{
			cout << "Karatsuba (iterative): X * Y = ";
		}

		for (int i = 0; i < vecProd.size(); i++)
		{
				cout << vecProd.at(i);
		}
		cout << endl;
	}



	vector<int> Multiply::multVectors(vector<int> x, vector<int> y)
	{
		vector<int> res;
		int temp = x.at(0) * y.at(0);
		res.push_back(temp % 10);
		if (temp / 10 != 0)
		{
			res.insert(res.begin(), temp / 10);
		}
		return res;
	}

	vector<int> Multiply::addVectors(vector<int> x, vector<int> y)
	{
		vector<int> res;
		int temp,carry=0;
		
		int size = MAX(x.size(), y.size());
		while (x.size() < size)
		{
			x.insert(x.begin(), 0);
		}

		while (y.size() < size)
		{
			y.insert(y.begin(), 0);
		}

		while (x.size() != 0 && y.size() != 0)
		{
			temp = x.back() + y.back() + carry;
			res.insert(res.begin(), (temp % 10));
			carry = temp / 10;
			x.pop_back();
			y.pop_back();
		}
		if (carry!=0)
			res.insert(res.begin(), carry);
		return res;
	}

	vector<int> Multiply::subVectors(vector<int> x, vector<int> y)
	{
		vector<int> res;
		int temp, carry = 0;

		int size = MAX(x.size(), y.size());
		while (x.size() < size)
		{
			x.insert(x.begin(), 0);
		}

		while (y.size() < size)
		{
			y.insert(y.begin(), 0);
		}

		while (x.size() != 0 && y.size() != 0)
		{
			temp = x.back() - y.back() - carry;
			if (temp < 0)
			{
				temp += 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			res.insert(res.begin(), temp);
			x.pop_back();
			y.pop_back();
		}

		//res.insert(res.begin(), carry);
		return res;

	}

	void Multiply::shift(vector<int>& x, int powerOfTen)
	{
		for (int i = 0; i < powerOfTen; i++)
		{
			x.push_back(0);
		}
	}


		

	void Multiply::LongMult()
	{
	
		int iX, iY, carry = 0, temp = 0;
		set_product();
		for (iY = n-1; iY >= 0; iY--)
		{
			for (iX = n-1 ; iX >= 0; iX--)
			{
				temp = (product[iX + iY + 1] + (X[iX] * Y[iY]) + carry);
				product[iX + iY + 1] = temp % 10;
				carry = temp / 10;
			}
			product[iX + iY+1] = carry;
			carry = 0;
		}
	}

	vector<int> Multiply::karatsuba(vector<int>x, vector<int>y)
	{

		int size = MAX(x.size(), y.size());
		if (size == 1)
		{
			return (multVectors(x, y));
		}
		if (size % 2 == 1)
			size++;

		while (x.size() < size)
		{
			x.insert(x.begin(), 0);
		}

		while (y.size() < size)
		{
			y.insert(y.begin(), 0);
		}


		int m = size / 2;

		vector<int> a(x.begin(), x.begin() + m);
		vector<int> b(x.begin() + m, x.end());

		vector<int> c(y.begin(), y.begin() + m);
		vector<int> d(y.begin() + m, y.end());

		vector<int> p0 = karatsuba(a, c);
		vector<int> p2 = karatsuba(b, d);

		vector<int> a_b(addVectors(a, b));
		vector<int> c_d(addVectors(c, d));
		vector<int> sub1 = karatsuba(a_b, c_d);


		vector<int> ac_bd = addVectors(p0, p2);
		vector<int>	p1 = subVectors(sub1, ac_bd);
		shift(p0, size);
		shift(p1, m);

		return (addVectors(addVectors(p0, p1), p2));

	}

	void Multiply::nrka()
	{
		Stack s;
		ItemType curr, next;
		vector<int> returnVal;

		int size = MAX(vecX.size(), vecY.size());
		curr.SetItem(size, size / 2, vecX, vecY, START);
		s.push(curr);

		while (!s.IsEmpty())
		{
			curr = s.pop();
			if (curr.line == START)
			{
				size = MAX(curr.x.size(), curr.y.size());

				if (size == 1)
				{
					returnVal = multVectors(curr.x, curr.y);
				}
				else
				{
					//size = MAX(curr.x.size(), curr.y.size());
					if (size % 2 == 1)
						size++;

					while (curr.x.size() < size)
					{
						curr.x.insert(curr.x.begin(), 0);
					}

					while (curr.y.size() < size)
					{
						curr.y.insert(curr.y.begin(), 0);
					}

					curr.line = AFTER_FIRST;
					curr.size = size;
					curr.m = size / 2;

					curr.a.insert(curr.a.begin(), curr.x.begin(), curr.x.begin() + curr.m);
					curr.b.insert(curr.b.begin(), curr.x.begin() + curr.m, curr.x.end());
					
					curr.c.insert(curr.c.begin(), curr.y.begin(), curr.y.begin() + curr.m);
					curr.d.insert(curr.d.begin(), curr.y.begin() + curr.m, curr.y.end());
					s.push(curr);

					next.SetItem(curr.size / 2, curr.m / 2, curr.a, curr.c, START);
					s.push(next);
				}
			}
			else if (curr.line == AFTER_FIRST)
			{
				curr.vecRes1 = returnVal;
				curr.line = AFTER_SECOND;
				s.push(curr);

				next.SetItem(curr.size / 2, curr.m/2, curr.b, curr.d, START);
				s.push(next);
			}
			else if (curr.line == AFTER_SECOND)
			{
				curr.vecRes3 = returnVal;
				curr.line = AFTER_THIRD;
				curr.a_b = addVectors(curr.a, curr.b);
				curr.c_d = addVectors(curr.c, curr.d);
				s.push(curr);

				next.SetItem(curr.size / 2, curr.m / 2, curr.a_b, curr.c_d, START);
				s.push(next);
			}
			else if (curr.line == AFTER_THIRD)
			{
				curr.vecRes2 = returnVal;

				curr.ac_bd = addVectors(curr.vecRes1, curr.vecRes3);
				curr.subOfPos = subVectors(curr.vecRes2, curr.ac_bd);

				shift(curr.vecRes1, curr.size);
				shift(curr.subOfPos, curr.m);
				returnVal = (addVectors(addVectors(curr.vecRes1, curr.subOfPos), curr.vecRes3));

			}
		} 
		vecProd = returnVal;
	}






	
	
}
