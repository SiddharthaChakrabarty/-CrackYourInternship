#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPalindrome(string str, int i, int j)
    {
        while (i < j)
        {
            if (str[i] == str[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        }
        return true;
    }
};