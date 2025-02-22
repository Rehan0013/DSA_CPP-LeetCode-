//--------------LeetCode 18------------------------------

// 4 Sum
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

#include <iostream>
using namespace std;

void fourSum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {

            if(j > i + 1 && arr[j] == arr[j - 1]) continue;
            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = arr[i] + arr[j] + arr[left] + arr[right];
                if (sum == target)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[left] << " " << arr[right] << endl;
                    while (left < right && arr[left] == arr[left + 1])
                    {
                        left++;
                    }
                    while (left < right && arr[right] == arr[right - 1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
}

int main()
{
    int nums[5] = {2,2,2,2,2};
    int target = 0;

    fourSum(nums, 5, target);

    return 0;
}