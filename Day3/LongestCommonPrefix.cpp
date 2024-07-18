#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        string firstEle = strs[0];
        string lastEle = strs[strs.size() - 1];
        string ans = "";
        for (int i = 0; i < min(firstEle.length(), lastEle.length()); i++)
        {
            if (firstEle[i] != lastEle[i])
                break;
            ans += firstEle[i];
        }
        return ans;
    }
};