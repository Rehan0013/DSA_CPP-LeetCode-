// --------------LeetCode 633------------

// Sum of Square Numbers

// Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

// Example 1:

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:

// Input: c = 3
// Output: false

#include <iostream>
using namespace std;

bool judgeSquareSum(int c) {
        int left = 0;
        int right = static_cast<int>(sqrt(c));

        while (left <= right) {
            int sum = left * left + right * right;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                left++;
            } else {
                right--;
            }
        }

        return false;
}

int main() {

    int c = 5;

    cout << judgeSquareSum(c) << endl;

    return 0;
}