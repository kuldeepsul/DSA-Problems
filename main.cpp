#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "Graph.h"

int main()
{

	std::vector<std::vector<int>> prereq = {
		{1, 2}, {1, 3}, {1, 4} , {3,4} , {4,5}
	};
	
	std::vector <int> res = Node::findRedundantConnection(prereq);
	return 0;
};