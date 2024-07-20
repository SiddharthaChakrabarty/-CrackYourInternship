#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        int n = s.length();
        bool digitSeen = false, eSeen = false, dotSeen = false;
        int cntOp = 0;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                digitSeen = true;
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (cntOp == 2)
                    return false;
                if (i > 0 && (s[i - 1] != 'E' && s[i - 1] != 'e'))
                    return false;
                if (i == (n - 1))
                    return false;
                cntOp++;
            }
            else if (s[i] == 'E' || s[i] == 'e')
            {
                if (eSeen)
                    return false;
                if (!digitSeen)
                    return false;
                if (i == (n - 1))
                    return false;
                eSeen = true;
            }
            else if (s[i] == '.')
            {
                if (eSeen || dotSeen)
                    return false;
                if (i == (n - 1) && !digitSeen)
                    return false;
                dotSeen = true;
            }
            else
                return false;
        }
        return true;
    }
};