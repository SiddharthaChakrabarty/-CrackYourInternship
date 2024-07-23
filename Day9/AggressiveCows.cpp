//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    bool isPossible(vector<int> &stalls, int n, int k, int mid)
    {
        int cntCows = 1, last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= mid)
            {
                cntCows++;
                last = stalls[i];
            }
            if (cntCows == k)
                return true;
        }
        return false;
    }

public:
    int solve(int n, int k, vector<int> &stalls)
    {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int ans = 0;
        int start = 1, end = stalls[n - 1] - stalls[0];
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isPossible(stalls, n, k, mid))
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends