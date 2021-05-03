# Karatsuba-Algorithm
This is an implimentation of 2 karatsuba algorithms for big number multiplication (recursive and non-recursive), alongside a long multiplication algorithm

This program recieves 3 positive integers n,x,y in 3 seperate rows as input from stdin.
Let n be the number of digits in x and y, two large positive integers.
if x and y number of digits isnt equal, add leading 0' to the shorter intger so they will end the same length.

The program output will be the product of x*y and its length will be 2n digits at the most.

The multiplication procdure is done by 3 algorithms:
1) long nultiplication algorithm (LongMult)
2) Recursive Karatsuba algorithm for big integers (karatsuba)
3) Non-Recursive Karatsuba algorithm for big integers (nrka) , utilizing Stack data structure

