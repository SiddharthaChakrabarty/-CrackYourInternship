#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        // Your code here
        vector<int> hash(256, 0);
        int n = s.size(), m = p.size(), l = 0, r = 0, minLen = INT_MAX, sIndex = -1, cnt = 0;
        for (int i = 0; i < m; i++)
            hash[p[i]]++;
        while (r < n)
        {
            if (hash[s[r]] > 0)
            {
                cnt++;
            }
            hash[s[r]]--;
            while (cnt == m)
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        return (sIndex == -1) ? "-1" : s.substr(sIndex, minLen);
    }
};