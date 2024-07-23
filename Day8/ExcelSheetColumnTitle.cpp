#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";
        while (columnNumber > 0)
        {
            columnNumber--;
            int num = columnNumber % 26;
            ans = char(num + 'A') + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};