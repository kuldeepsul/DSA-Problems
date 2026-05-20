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
    int i = 0;
    unsigned char a  = i ;
    for (int j = 0; j < 256; ++j)
    {
        std::cout << a << " : " << int{ a } << std::endl;
        a++;
    }
    return 0;
}
