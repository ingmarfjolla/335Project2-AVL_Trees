/*
TITLE: HW2Q1.CC
NAME : INGMAR FJOLLA
PROFESSOR: ANITA RAJA
HW 2 Question 1

*/




#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

Implement the STL find routine that returns the iterator containing the 
first occurrence of x in the range that begins at start and extends up to but not including end. 
If x is not found, end is returned. This is a non-class (global function) with signature
*/
template <typename Iterator, typename object>
Iterator my_find(Iterator start, Iterator end, const object & x)
{

	while(start!=end)
	{
		//must dereference the iterator so we see get the value of what it is pointing to
		if(*start==x)
		{
			return start;
		}
		start++;
	}
	//not found
	return end;
}