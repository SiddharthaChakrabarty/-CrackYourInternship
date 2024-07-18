#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        string ans = "";
        int n = haystack.size(), m = needle.size();
        if (m > n)
            return -1;
        int start = 0, end = m - 1;
        while (end < n)
        {
            if (haystack.substr(start, m) == needle)
                return start;
            else
            {
                start++;
                end++;
            }
        }
        return -1;
    }
};