#pragma once
#include <iostream>
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
    int longestConsecutive(vector<int>& nums);
    bool isPalindrome(string s);
    std::vector <int> twoSum(std::vector<int>& numbers, int target);
};

int BinSearch (std::vector <int>& nums, int low, int high, int value);

int findMin(std::vector <int>& nums);
int calculate_time(std::vector <int>& nums, int rate);
int minEatingSpeed(vector<int>& piles, int h);
int search(vector<int>& nums, int target);
std::vector <int> Merge(std::vector <int>& leftarray, std::vector <int>& rightarray);
std::vector <int> MergeSort(std::vector <int>& array);

std::vector <int> mergesort2(std::vector<int> nums, int low, int high);