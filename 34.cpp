//---------------LeetCode 34

// Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

#include<iostream>
#include<vector>
using namespace std;

void searchRange(int nums[], int size,int target) {
        int left = 0, right = size - 1;
        int first = -1, last = -1;
    
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (nums[mid] == target) first = mid;
        }

        left = 0, right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (nums[mid] == target) last = mid;
        }

        cout << first << " " << last;
    }

int main() {
    int a[6] = {5,7,7,8,8,10};
    int target = 8;

    searchRange(a, 6, target);

    return 0;
}