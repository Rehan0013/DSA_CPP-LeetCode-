//----------------LeetCode 15---------------------

//3 Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 
// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

#include<iostream>
using namespace std;

void threeSum(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if(sum == 0) {
                cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
                while(left < right && arr[left] == arr[left + 1]) {
                    left++;
                }
                while(left < right && arr[right] == arr[right - 1]) {
                    right--;
                }

            left++;
            right--;
            } else if(sum < 0) {
                left++;
            } else {
                right--;
            }

        }
    }
}

int main() {
    int nums[6] = {-1,0,1,2,-1,-4};

    threeSum(nums, 6);

    return 0;
}