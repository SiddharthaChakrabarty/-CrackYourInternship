#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int BASE = 1e6;

    int RabinKarp(string source, string target)
    {
        int n = source.size();
        int m = target.size();

        if (source == "" || target == "")
        {
            return -1;
        }
        if (m > n)
        {
            return -1;
        }

        int power = 1;
        for (int i = 0; i < m; i++)
        {
            power = (power * 31) % BASE;
        }

        int targetcode = 0;
        int sourcecode = 0;

        for (int i = 0; i < m; i++)
        {
            targetcode = (targetcode * 31 + (target[i] - 'a' + 1)) % BASE;
            sourcecode = (sourcecode * 31 + (source[i] - 'a' + 1)) % BASE;
        }

        for (int i = 0; i <= n - m; i++)
        {
            if (i > 0)
            {
                sourcecode = (sourcecode * 31 + (source[i + m - 1] - 'a' + 1)) % BASE;
                sourcecode = (sourcecode - (source[i - 1] - 'a' + 1) * power % BASE + BASE) % BASE;
            }

            if (sourcecode == targetcode)
            {
                if (source.substr(i, m) == target)
                {
                    return i;
                }
            }
        }

        return -1;
    }

    int strStr(string haystack, string needle)
    {
        int x = RabinKarp(haystack, needle);
        return x;
    }
};