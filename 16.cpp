//-------------LeetCode 16-------------------

// 3 Sum Closest
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


#include<iostream>
using namespace std;

int threeSum(int arr[], int target, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int closest_sum = arr[0] + arr[1] + arr[2];

    for(int i = 0; i < n; i++) {
        int left = i + 1;
        int right =  n - 1;

        while(left < right) {
            int current_sum = arr[i] + arr[left] + arr[right];

            if(current_sum == target) return target;

            if(abs(target - current_sum) < abs(target - closest_sum)) closest_sum = current_sum;
            else if(closest_sum > target) right--;
            else left++;
        }

    }
    return closest_sum;
}

int main() {
    int nums[4] = {-1,2,1,-4};
    int target = 1;

    cout << threeSum(nums, target, 4) << endl;

    return 0;
}