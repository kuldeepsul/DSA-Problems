
#include "Array.h"




// Encoding String
std::string Array::encode(std::vector<std::string>& strs) {
    std::string msg;

    for (std::string& s : strs)
    {
        for (char& c : s)
        {

            char e = c + 2;
            msg += e;

        }
        msg.push_back('\0');

    }

    return msg;

}
// Decoding string
std::vector<std::string> Array::decode(std::string s) {

    std::vector <std::string> strs2;
    std::string word;
    for (int i{ 0 }; i < size(s); i++)
    {
        

        if (s[i] == '\0')
        {
            strs2.push_back(word);
            word.clear();
        }
       
        else
        {
            char d = s[i] - 2;
            word.push_back(d);
        }
    }
    return strs2;

    
}

bool Array::isValidSudoku(vector<vector<char>>& board)
{
    std::map <int, int> f_map;

    // check rows
    for (size_t i{ 0 }; i < 9; i++)
    {
        for (size_t j{ 0 }; j < 9; j++)
        {
            f_map[board[i][j]]++;
            if (board[i][j] != '.')
            {
                if (f_map[board[i][j]] > 1)
                {
                    return false;
                }
            }
        }
        f_map.clear();
    }
    f_map.clear();
    // check cols
    for (size_t i{ 0 }; i < 9; i++)
    {
        for (size_t j{ 0 }; j < 9; j++)
        {
            f_map[board[j][i]]++;
            if (board[j][i] != '.')
            {
                if (f_map[board[j][i]] > 1)
                {
                    return false;
                }
            }
        }
        f_map.clear();
    }

    // check box
    std::map <int, int> b1;
    std::map <int, int> b2;
    std::map <int, int> b3;

    for (size_t i{ 0 }; i < 9; i++)
    {
        if (i == 3 || i == 6)
        {
            b1.clear();
            b2.clear();
            b3.clear();
        }
        for (size_t j{ 0 }; j < 9; j++)
        {
            if (j < 3)
            {
                b1[board[i][j]]++;
                if (board[i][j] != '.')
                {
                    if (b1[board[i][j]] > 1)
                    {
                        return false;
                    }
                }
            }
            else if (j > 2 && j < 6)
            {
                b2[board[i][j]]++;
                if (board[i][j] != '.')
                {
                    if (b2[board[i][j]] > 1)
                    {
                        return false;
                    }
                }
            }
            else
            {
                b3[board[i][j]]++;
                if (board[i][j] != '.')
                {
                    if (b3[board[i][j]] > 1)
                    {
                        return false;
                    }
                }
            }
        }

    }


    return true;
}

vector<int> Array::productExceptSelf(vector<int>& nums) 
{

    std::vector <int> pref(size(nums));
    std::vector <int> suf(size(nums));
    int prod{ 1 };
    int len = int(size(nums));
    for (int i{ 0 }; i < len; i++)
    {
        if (i == 0)
        {
            pref[i] = 1;
        }
        else
        {
            prod = prod * nums[i - 1];
            pref[i] = prod;
        }
    }

    prod = 1;
    for (int i{ len - 1 }; i >= 0; i--)
    {
        if (i == int(size(nums)) - 1)
        {
            suf[i] = 1;
        }
        else
        {
            prod = prod * nums[i + 1];
            suf[i] = prod;
        }
    }
    std::vector <int> ans(len);
    for (int i{ 0 }; i < len; i++)
    {
        ans[i] = suf[i] * pref[i];
    }
    return ans;
}