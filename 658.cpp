// ----------LeetCode 658---------------

// Find K Closest Elements

// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
 

// Example 1:

// Input: arr = [1,2,3,4,5], k = 4, x = 3

// Output: [1,2,3,4]

// Example 2:

// Input: arr = [1,1,2,3,4,5], k = 4, x = -1

// Output: [1,1,2,3]

#include <iostream>
#include <vector>
using namespace std;

vector<int> closetElements(vector<int>& arr, int k, int x) {
    int left = 0;
    int right = arr.size() - k;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

     return vector<int>(arr.begin() + left, arr.begin() + left + k);
}

int main() {
    vector<int> arr = {1,1,2,3,4,5};
    int k = 4, x = -1;

    vector<int> result = closetElements(arr, k, x);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}