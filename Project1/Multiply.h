#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>
#include"Stack.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

namespace DSP1 //Data Structurs Project 1
{

	class Multiply
	{

	private:
		
		vector<int> vecX, vecY, vecProd;
		int* X, * Y;
		int* product;
		unsigned int n;


	public:
		Multiply(const unsigned int& _n);
		Multiply();
		~Multiply();

		bool set_n(const unsigned int& _n);
		const unsigned int& get_n() { return n; }
		void resizeX(int n);
		void resizeY(int n);
		void resizeProduct(int n);
		bool set_X(char* str);
		bool set_Y(char* str);
		bool set_product();
		const int* get_product()const;
		void print_product();
		void print_vecProd(int);


		vector<int> multVectors(vector<int> x, vector<int> y);
		vector<int> addVectors(vector<int> x, vector<int> y);
		vector<int> subVectors(vector<int> x, vector<int> y);
		void shift(vector<int>& x, int powerOfTen);
		vector<int>& shiftV2(vector<int>& x, int powerOfTen);


		void LongMult();

		void KaratsubaHelper() { vecProd = karatsuba(vecX, vecY); }
		vector<int> karatsuba(vector<int> x, vector<int>y);

		void nrka(); //Non-Recursive Karatsuba Algorithm

		void timesLM()
		{
			for (int i = 0; i < 3; i++)
			{
				auto start = chrono::high_resolution_clock::now();

				// unsync the I/O of C and C++.
				ios_base::sync_with_stdio(false);
				
				LongMult();
				auto end = chrono::high_resolution_clock::now();

				// Calculating total time taken by the program.
				double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

				time_taken *= 1e-9;

				ofstream myfile("Measure-LM.txt"); // The name of the file

				myfile << "Time taken by function <LongMult> is : " << fixed << time_taken << setprecision(9);
				myfile << " sec" << endl;
				myfile.close();

			}
		}

		void timesRK()
		{
			for (int i = 0; i < 3; i++)
			{
				auto start = chrono::high_resolution_clock::now();

				// unsync the I/O of C and C++.
				ios_base::sync_with_stdio(false);

				KaratsubaHelper();
				auto end = chrono::high_resolution_clock::now();

				// Calculating total time taken by the program.
				double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

				time_taken *= 1e-9;

				ofstream myfile("Measure-RK.txt"); // The name of the file

				myfile << "Time taken by function <Karatsuba> is : " << fixed << time_taken << setprecision(9);
				myfile << " sec" << endl;
				myfile.close();

			}
		}

		void timesIK()
		{
			for (int i = 0; i < 3; i++)
			{
				auto start = chrono::high_resolution_clock::now();

				// unsync the I/O of C and C++.
				ios_base::sync_with_stdio(false);

				nrka();
				auto end = chrono::high_resolution_clock::now();

				// Calculating total time taken by the program.
				double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

				time_taken *= 1e-9;

				ofstream myfile("Measure-IK.txt"); // The name of the file

				myfile << "Time taken by function <nrka(non recursive karatsuba algorithm)> is : " << fixed << time_taken << setprecision(9);
				myfile << " sec" << endl;
				myfile.close();

			}
		}
	};

}