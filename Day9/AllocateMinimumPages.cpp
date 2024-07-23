//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
private:
    bool isPossible(int arr[], int n, int m, long long mid)
    {
        int cnt = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                cnt++;
                i--;
                sum = 0;
            }
            if (cnt > m)
                return false;
        }
        if (cnt > m)
            return false;
        return true;
    }

    long long helper(int arr[], int n, int m, int mini, long long sum)
    {
        long long start = mini, end = sum;
        long long ans = 0;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            if (isPossible(arr, n, m, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }

public:
    // Function to find minimum number of pages.

    long long findPages(int n, int arr[], int m)
    {
        // code here
        long long sum = 0;
        if (n < m)
            return -1;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            mini = min(mini, arr[i]);
        }
        return helper(arr, n, m, mini, sum);
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends