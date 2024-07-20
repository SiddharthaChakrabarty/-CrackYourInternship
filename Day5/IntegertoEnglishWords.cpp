#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<string> THOUSANDS = {"", "Thousand", "Million", "Billion"};
    vector<string> LESS_THAN_TWENTY = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                                       "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                       "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
                           "Ninety"};

    void helper(string &help, int num)
    {
        if (num == 0)
            return;
        else if (num < 20)
        {
            help = help + LESS_THAN_TWENTY[num] + " ";
            return;
        }
        else if (num < 100)
        {
            help = help + TENS[num / 10] + " ";
            helper(help, num % 10);
        }
        else
        {
            help = help + LESS_THAN_TWENTY[num / 100] + " Hundred ";
            helper(help, num % 100);
        }
    }

public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        string ans = "";
        int idx = 0;
        while (num > 0)
        {
            if (num % 1000 != 0)
            {
                string help = "";
                helper(help, num % 1000);
                ans = help + THOUSANDS[idx] + " " + ans;
            }
            idx++;
            num /= 1000;
        }
        idx = ans.length() - 1;
        while (ans[idx] == ' ')
            idx--;
        return ans.substr(0, idx + 1);
    }
};