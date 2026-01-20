// -----------LeetCode 852---------------

// Peak Index in a Mountain Array

// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

// Example 3:

// Input: arr = [0,10,5,2]

// Output: 1


#include <iostream>
#include <vector>
using namespace std;

int peakIndex(vector<int>& arr) {
    int left = 1;
    int right = arr.size() - 1;

    while(left < right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<int> arr = {0,1,2,3,4,5,6,5,4,3,1,0};

    cout << peakIndex(arr) << endl;

}