#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length();
        if (n < m)
            return "";
        int sIndex = -1, minLen = INT_MAX;
        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++)
        {
            mp[t[i]]++;
        }
        int cnt = 0;
        int l = 0, r = 0;
        while (r < n)
        {
            if (mp[s[r]] > 0)
            {
                cnt++;
            }
            mp[s[r]]--;
            while (cnt == m)
            {
                int len = r - l + 1;
                if (len < minLen)
                {
                    minLen = len;
                    sIndex = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};