#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

class Backtracking
{
public:
    static std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        dfsrev(nums, 0, subset, res);
        return res;
    }

    static void dfs(const std::vector<int>& nums, int i, std::vector<int>& subset, std::vector<std::vector<int>>& res)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,i + 1,subset,res);
        subset.pop_back();
        dfs(nums,i+1,subset,res);
    }

    static void dfsrev(const std::vector<int>& nums, int i, std::vector<int>& subset, std::vector<std::vector<int>>& res)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }
        
        dfsrev(nums, i + 1, subset, res);
        subset.push_back(nums[i]);
        
        dfsrev(nums, i + 1, subset, res);
        subset.pop_back();
    }

    static void step(const std::vector <int>& nums, const int& target, int i, int& sum, std::vector<std::vector<int>>& res, std::vector <int>& temp)
    {
        if (sum == target)
        {
            res.push_back(temp);
            return;
        }
        else if (sum > target)
        {
            return;
        }
        if (i == nums.size())
        {
            i = 0;
            return;
        }

        temp.push_back(nums[i]);
        sum = sum + temp.back();
        step(nums, target, i , sum, res, temp);
        sum = sum - temp.back();
        temp.pop_back();
        step(nums, target, i + 1, sum, res, temp);
   

    }
    static std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target)
    {
        std::vector <std::vector <int>> res;
        std::vector <int> temp;
        int sum = 0;
        step(nums, target, 0, sum, res, temp);
        return res;

    }

    static void step2(const std::vector <int>& nums, const int& target, int i, int& sum, std::vector<std::vector<int>>& res, std::vector <int>& temp)
    {
        if (sum == target)
        {
            res.push_back(temp);
            return;
        }
        else if (sum > target)
        {
            return;
        }
        if (i == nums.size())
        {
            i = 0;
            return;
        }


        temp.push_back(nums[i]);
        sum = sum + temp.back();
        step(nums, target, i + 1 , sum, res, temp);
        sum = sum - temp.back();
        temp.pop_back();
        step(nums, target, i + 1, sum, res, temp);


    }
    static std::vector<std::vector<int>> combinationSum2(std::vector<int>& nums, int target)
    {
        std::vector <std::vector <int>> res;
        std::vector <int> temp;
        int sum = 0;
        step(nums, target, 0, sum, res, temp);
        return res;

    }


    static void permutationstep(std::vector <std::vector<int>>& result, const std::vector <int>& nums, std::vector <int>& temp,
        std::vector <bool> &currentstate)
    {   
    
        if (temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }

        for (int i{0} ; i < currentstate.size() ; i++)
        {
            if (!currentstate[i])
            {
                temp.push_back(nums[i]);
                currentstate[i] = true;
                permutationstep(result, nums, temp, currentstate);
                currentstate[i] = false;
                temp.pop_back();
            }
        }

    }


    static std::vector<std::vector<int>> permute(std::vector<int>&nums) 
    {
        std::vector <std::vector<int>> result;
        std::vector <int> temp;
        std::vector <bool> currentstate;
        for (int i : nums)
        {
            currentstate.push_back(false);
        }
        permutationstep(result, nums, temp , currentstate);
        
        return result;
    }

    static void permutationstep2(std::vector <std::vector<int>>& result, const std::vector<int> &nums)
    {

    }


    static std::vector<std::vector<int>> permute2(std::vector<int>& nums)
    {
        std::vector <std::vector<int>> result;;
        permutationstep2(result, nums);

        return result;
    }
};