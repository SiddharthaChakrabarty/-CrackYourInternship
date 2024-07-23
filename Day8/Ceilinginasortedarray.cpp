#include <bits/stdc++.h>
using namespace std;

int getFloor(vector<int> &a, int n, int x)
{
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] > x)
            end = mid - 1;
        else
        {
            ans = a[mid];
            start = mid + 1;
        }
    }
    return ans;
}

int getCeil(vector<int> &a, int n, int x)
{
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] < x)
            start = mid + 1;
        else
        {
            ans = a[mid];
            end = mid - 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    // Write your code here.
    int floor = getFloor(a, n, x);
    int ceil = getCeil(a, n, x);
    return {floor, ceil};
}