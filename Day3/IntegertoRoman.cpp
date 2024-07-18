#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string ans = "";
        vector<pair<string, int>> vec = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
        for (int i = 0; i < vec.size(); i++)
        {
            if (num / vec[i].second)
            {
                int cnt = num / vec[i].second;
                for (int j = 0; j < cnt; j++)
                    ans += vec[i].first;
                num = num % vec[i].second;
            }
        }
        return ans;
    }
};