#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int carry = 0, i = a.length() - 1, j = b.length() - 1;
        string ans = "";
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            carry = sum / 2;
            sum = sum % 2;
            ans = char(sum + '0') + ans;
        }
        return ans;
    }
};