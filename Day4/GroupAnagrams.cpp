#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (string el : strs)
        {
            string s = el;
            sort(el.begin(), el.end());
            mp[el].push_back(s);
        }
        for (auto vec : mp)
        {
            ans.push_back(vec.second);
        }
        return ans;
    }
};