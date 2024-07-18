//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    unordered_map<int, int> mp;
    vector<vector<int>> ans;
    void solve(vector<int> arr, set<int> se, int i, vector<int> v)
    {
        if (i >= arr.size())
        {
            ans.push_back(v);
            return;
        }

        for (int element : se)
        {
            if (mp[element] > 0)
            {
                mp[element]--;
                v.push_back(element);
                solve(arr, se, i + 1, v);
                mp[element]++;
                v.pop_back();
            }
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        set<int> se;

        for (auto val : arr)
        {
            se.insert(val);
            mp[val]++;
        }

        vector<int> v;
        solve(arr, se, 0, v);

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr, n);
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends