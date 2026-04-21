#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

class Backtracking
{
public:
    static std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        dfs(nums, 0, subset, res);
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

    static void step2(const std::vector <int>& nums, int target, int i, std::vector<std::vector<int>>& res, std::vector <int>& temp)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        else if (target < 0)
        {
            return;
        }
        if (i >= nums.size())
        {
            return;
        }

        temp.push_back(nums[i]);
        target -= nums[i];
        step2(nums, target, i + 1, res, temp);
        target += temp.back();
        temp.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        {
            i++;
        }
        step2(nums, target, i + 1 , res, temp);


    }
    static std::vector<std::vector<int>> combinationSum2(std::vector<int>& nums, int target)
    {
        std::vector <std::vector <int>> res;
        std::vector <int> temp;
        std::stable_sort(nums.begin(),nums.end());
        step2(nums, target, 0, res, temp);
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


    static void perm(std::vector<std::vector<int>> &res, std::vector<int> temp ,int &sum,const int &target)
    {
        if (sum > 0)
        {
            return;
        }
        if (sum < -target)
        {
            return;
        }
        if (temp.size() == 2 * target)
        {
            if (sum == 0)
            {
                res.push_back(temp);
            }
            return;
        }

        temp.push_back(-1);
        sum -= 1;
        perm(res, temp, sum, target);
        temp.pop_back();
        sum += 1;

        temp.push_back(1);
        sum += 1;
        perm(res, temp, sum, target);
        temp.pop_back();
        sum -= 1;

    }

    static std::vector<std::vector<int>> genparenthesis(int n)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
        int sum = 0;
        perm(res,temp,sum,n);

        return res;
        
    }

    static void permstr(std::vector<std::string>& res, std::string &temp, int& sum, const int& target)
    {
        if (sum > 0)
        {
            return;
        }
        if (sum < -target)
        {
            return;
        }
        if (temp.size() == 2 * target)
        {
            if (sum == 0)
            {
                res.push_back(temp);
            }
            return;
        }

        temp.push_back('(');
        sum -= 1;
        permstr(res, temp, sum, target);
        temp.pop_back();
        sum += 1;

        temp.push_back(')');
        sum += 1;
        permstr(res, temp, sum, target);
        temp.pop_back();
        sum -= 1;

    }

    static std::vector<std::string> genparenthesisstr(int n)
    {
        std::vector<std::string> res;
        std::string temp;
        int sum = 0;
        permstr(res, temp, sum, n);

        return res;

    }
    static bool searchnearby(std::vector<std::vector<char>>& board, std::string word, const int& i, const int& j , int n, std::map <std::pair<int, int>, int> &cur_path)
    {
        if (n >= word.size())
        {
            return true;
        }

        bool left = false;
        bool right = false;
        bool up = false;
        bool down = false;
        

        if (i)
        {
            if (board[i - 1][j] == word[n])
            {
                auto it = cur_path.find({i-1,j});
                if (it == cur_path.end())
                {
                    cur_path[{i - 1, j}]++;
                    up = searchnearby(board, word, i - 1, j, n + 1,cur_path);
                    cur_path.erase({ i - 1, j });
                }
            }
        }
        if (j)
        {
            if (board[i][j - 1] == word[n])
            {
                auto it = cur_path.find({i,j-1});
                if (it == cur_path.end())
                {
                    cur_path[{i, j - 1}]++;
                    left = searchnearby(board, word, i, j - 1, n + 1, cur_path);
                    cur_path.erase({i,j-1});
                }

            }
        }
        if (i != board.size() - 1)
        {
            if (board[i + 1][j] == word[n])
            {
                auto it = cur_path.find({i+1,j});
                if (it == cur_path.end())
                {
                    cur_path[{i + 1, j}]++;
                    down = searchnearby(board, word, i + 1, j, n + 1,cur_path);
                    cur_path.erase({i+1,j});
                }
            }
        }
        if (j != board[0].size() - 1)
        {
            if (board[i ][j + 1] == word[n])
            {
                auto it = cur_path.find({i,j+1});
                if (it == cur_path.end())
                {
                    cur_path[{i, j + 1}]++;
                    right = searchnearby(board, word, i, j + 1, n + 1,cur_path);
                    cur_path.erase({i,j+1});
                }  
            }
        }

        return left || right || up || down;
    }
    
    static bool search(std::vector<std::vector<char>>& board, std::string word,int &i , int &j)
    {
        std::map <std::pair<int,int>,int>cur_path;
        for (int k = i; k < board.size(); k++)
        {
            for (int l = j; l < board[0].size(); l++)
            {
                bool cur = false;
                if (board[k][l] == word[0])
                {
                    cur_path[{k,l}]++;
                    cur = searchnearby(board, word, k, l, 1,cur_path);
                    cur_path.clear();
                }
                if (cur)
                {
                    return true;
                }
            }
        }
        return false;
    }

    static bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        int i = 0;
        int j = 0;
        return search(board,word,i,j);
    }

    static void getcombinations(int i, int j, std::vector<std::string>& res, std::string& temp, const std::vector <std::string> &input)
    {
        for (int k = i; k < input.size(); k++)
        {
            for (int l = j; l < input[i].size(); l++)
            {

            }
        }
    }

    static std::vector<std::string> LetterCombinations(std::string digit)
    {
        std::unordered_map <char,std::string> alphamap;
        alphamap['2'] = "abc";
        alphamap['3'] = "def";
        alphamap['4'] = "ghi";
        alphamap['5'] = "jkl";
        alphamap['6'] = "mno";
        alphamap['7'] = "pqrs";
        alphamap['8'] = "tuv";
        alphamap['9'] = "wxyz";
        std::vector <std::string> res;
        std::string temp;
        std::vector <std::string> input;
        for (auto it = alphamap.begin(); it != alphamap.end(); it++)
        {
            input.push_back(it->second);
        }
        getcombinations(0,0, res, temp, input);
    }
};