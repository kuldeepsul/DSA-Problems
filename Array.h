#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;

class Array
{
public:
    // Encoding String
    std::string encode(std::vector<std::string>& strs);
    // Decoding string
    std::vector<std::string> decode(std::string s);

    bool isValidSudoku(vector<vector<char>>& board);
    vector<int> productExceptSelf(vector<int>& nums);
};