#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> duplicate_char(string s, int n)
{

    // Write your code here.

    int arr[26] = {0};

    int m = 2;

    for (int i = 0; i < n; i++)
    {

        if (s[i] >= 'A' && s[i] <= 'Z')
        {

            arr[s[i] - 'A']++;
        }

        else if (s[i] >= 'a' && s[i] <= 'z')
        {

            arr[s[i] - 'a']++;

            m = 1;
        }
    }

    vector<pair<char, int>> x;

    for (int j = 0; j < 26; j++)
    {

        if (arr[j] > 1)
        {

            pair<char, int> ans;

            if (m == 1)
            {

                ans.first = j + 'a';
            }

            else
            {

                ans.first = j + 'A';
            }

            ans.second = arr[j];

            // arr[j] = 0;

            x.push_back(ans);
        }
    }

    return x;
}