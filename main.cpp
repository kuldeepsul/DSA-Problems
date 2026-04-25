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
	std::vector<std::vector<char>> grid = {
		{'1', '1', '0', '0', '1'},
		{'1', '1', '0', '0', '1'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}
	};
	
	int res = Backtracking::numIslands(grid);
	return 0;
};