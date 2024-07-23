//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        // Code here
        vector<pair<int, int>> vec;
        for (int i = 0; i < nums.size(); i++)
            vec.push_back({nums[i], i});
        int cnt = 0;
        sort(vec.begin(), vec.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == vec[i].second)
                continue;
            else
            {
                cnt++;
                swap(vec[i], vec[vec[i].second]);
                i--;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends