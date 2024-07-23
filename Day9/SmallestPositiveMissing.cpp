//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
private:
    int segregate(int arr[], int n)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= 0)
                swap(arr[i], arr[j++]);
        }
        return j;
    }

    int smallest(int arr2[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int x = abs(arr2[i]);
            if (x - 1 < n && arr2[x - 1] > 0)
                arr2[x - 1] *= -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr2[i] > 0)
                return i + 1;
        }
        return n + 1;
    }

public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        // Your code here
        int seg = segregate(arr, n);
        return smallest(arr + seg, n - seg);
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        // input number n
        int n;
        cin >> n;
        int arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        // calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends