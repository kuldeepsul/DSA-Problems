
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

////////////////////////////////////////////////////////////////////////////////
///////////////////////    Merge Sort     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

std::vector <int> Merge(std::vector <int>& leftarray, std::vector <int>& rightarray)
{
    std::vector <int> result;

    // Check until one of the array is not zero

    while (leftarray.size() && rightarray.size())
    {
        if (leftarray[0] <= rightarray[0])
        {
            result.push_back(leftarray[0]);
            leftarray.erase(leftarray.begin());
        }
        else
        {
            result.push_back(rightarray[0]);
            rightarray.erase(rightarray.begin());
        }
    }

    // Once an array is zero push remaining array into results

    if (leftarray.size())
    {
        while (leftarray.size())
        {
            result.push_back(leftarray[0]);
            leftarray.erase(leftarray.begin());
        }
    }
    if (rightarray.size())
    {
        while (rightarray.size())
        {
            result.push_back(rightarray[0]);
            rightarray.erase(rightarray.begin());
        }
    }


    return result;
}

std::vector <int> MergeSort(std::vector <int>& array)
{
    if (array.size() <= 1)
    {
        return array;
    }
    int length = int(array.size());

    int mid = length / 2;
    std::vector <int> left(array.begin(), array.begin() + mid);
    std::vector <int> right(array.begin() + mid, array.end());

    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left, right);
}

// For Strings

std::string merge_s(std::string& left, std::string& right)
{
    std::string result;

    while (!left.empty() && !right.empty())
    {
        if (left[0] <= right[0])
        {
            result.push_back(left[0]);
            left.erase(left.begin());
        }
        else if (left[0] > right[0])
        {
            result.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    while (right.length() != 0)
    {
        result.append(right);
        right.clear();
    }
    while (left.length() != 0)
    {
        result.append(left);
        left.clear();
    }
    return result;
}

std::string MergeSort_s(std::string& s)
{
    if (s.length() <= 1)
    {
        return s;
    }
    int mid = s.length() / 2;
    std::string lefts(s.begin(), s.begin() + mid);
    std::string rights(s.begin() + mid, s.begin() + s.length());

    lefts = MergeSort_s(lefts);
    rights = MergeSort_s(rights);

    return merge_s(lefts, rights);
}



////////////////////////////////////////////////////////////////////////////////
///////////////////////    Quick Sort     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int partition(std::vector <int>& array, int low, int high)
{
    int mid = low + (high - low) / 2;
    int pivot = array[mid];

    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do { i++; } while (array[i] < pivot);

        do { j--; } while (array[j] > pivot);

        if (j <= i)
        {
            return j;
        }
        // Swapping
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

}

void QuickSort(std::vector <int>& array, int low, int high)
{
    if (low < high)
    {
        int p = partition(array, low, high);                                // Returns the final position of the pivot

        QuickSort(array, low, p);
        QuickSort(array, p + 1, high);

    }
}


int Array::longestConsecutive(vector<int>& nums) {

    QuickSort(nums, 0, nums.size() - 1);
    int lcs{ 0 };
    int temp_lcs{ 0 };
    for (int i{ 0 }; i < nums.size(); i++)
    {
        if (i == 0)
        {
            temp_lcs = 1;
        }
        else
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                temp_lcs += 1;
            }
            else if (nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                if (lcs < temp_lcs)
                {
                    lcs = temp_lcs;
                    temp_lcs = 1;
                }
                else
                {
                    temp_lcs = 1;
                }
            }
        }
    }

    if (temp_lcs > lcs)
    {
        lcs = temp_lcs;
    }
    return lcs;
}

bool Array::isPalindrome(string s)
{
    if (s.size() == 1 || s.size() == 0)
    {
        return true;
    }

    int left = 0;
    int right = s.size() - 1;

    while (left != right)
    {
        if (!std::isalpha(static_cast <unsigned char> (s[left])))
        {
            left++;
            continue;
        }
        else
        {
            if (std::isupper(static_cast <unsigned char>(s[left])))
            {
                s[left] = std::tolower(static_cast <unsigned char>(s[left]));
            }
        }
        if (!std::isalpha(static_cast <unsigned char> (s[right])))
        {
            right--;
            continue;
        }
        else
        {
            if (std::isupper(static_cast <unsigned char>(s[right])))
            {
                s[right] = std::tolower(static_cast <unsigned char>(s[right]));
            }
        }

        if (s[left] == s[right])
        {
            left++;
            right++;
        }
        else
        {
            return false;
        }
    }
    return true;

}