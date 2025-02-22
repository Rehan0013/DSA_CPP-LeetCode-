//-------------LeetCode 11-------------------- 

// Container With Most Water

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

#include<vector>
#include<iostream>
using namespace std;

int maxArea(vector <int> & arr) {
    int maxi = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                int v = min(arr[i], arr[j]) * (j - i);
                maxi = max(maxi, v);
            }
        }
        return maxi;
    }

int main() {
    vector <int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(arr) << endl;

    return 0;
}