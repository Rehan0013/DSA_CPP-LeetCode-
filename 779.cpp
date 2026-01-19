// --------------LeetCode 779--------------

// K-th Symbol in Grammar

// On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

// Given row N and index K, return the K-th indexed symbol in Nth row. (The values of K are 1-indexed.) (1 indexed).

// Example 1:

// Input: N = 1, K = 1
// Output: 0
// Explanation: The first row is 0.
// Example 2:

// Input: N = 2, K = 1
// Output: 0
// Explanation: The second row is 01.
// Example 3:

// Input: N = 2, K = 2
// Output: 1
// Explanation: The second row is 01, and the second 0 is in the second position (i.e. the second character).
// Example 4:

// Input: N = 4, K = 5
// Output: 1
// Explanation: The fourth row is 0110, and the third 1 is in the second position (i.e. the second character).

#include <iostream>
using namespace std;

int kthGrammar(int n, int k) {
    if (n == 1) return 0;

    if (k % 2 == 0) {
        int ans = kthGrammar(n - 1, k / 2);
        if (ans == 0)
            return 1;
        else
            return 0;
    }
    else
        return kthGrammar(n - 1, k / 2 + 1);
}

int main() {
    int n = 4, k = 5;
    cout << kthGrammar(n, k) << endl;
    return 0;
}