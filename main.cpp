#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "Backtracking.h"

int main()
{
	std::vector <int> data = { 9,2,2,4,6,1,5 };
	std::vector<std::vector<char>> board = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	
	bool res = Backtracking::exist(board,"ABCD");
	return 0;
};