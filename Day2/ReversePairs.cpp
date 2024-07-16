#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high)
        {
            if (nums[i] < nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= high)
            temp[k++] = nums[j++];
        i = low;
        for (auto el : temp)
            nums[low++] = el;
    }

    int countPairs(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && nums[i] > (long long)((long long)2 * nums[right]))
                right++;
            cnt += right - (mid + 1);
        }
        return cnt;
    }

    int mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;
        int cnt = 0;
        int mid = low + (high - low) / 2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};