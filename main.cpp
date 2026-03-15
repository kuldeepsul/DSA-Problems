#include <iostream>
#include <vector>
#include "Array.h"
#include "Linked_List.h"

int main()
{
	std::vector <int> piles1 = { 3,4,5,6,1,2 };
	std::vector <int> piles2 = { 4,5,0,1,2,3 };
	std::vector <int> piles3 = { 2,1 };
	std::vector <int> piles4 = { 4,5,6,7,0,1,2 };
	std::vector <int> piles5 = { 2,3,1 };

	int result1 = search(piles1,1);


	return 0;
}