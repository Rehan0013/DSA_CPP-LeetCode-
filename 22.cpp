//---------------LeetCode 22 ------------------

// Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:

// Input: n = 1
// Output: ["()"]

#include<iostream>
#include<vector>
using namespace std;

void generateParenthesis(int n, int open, int close, string current, vector<string>& result) {
    if (open == n && close == n) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        generateParenthesis(n, open + 1, close, current + "(", result);
    }

    if (close < open) {
        generateParenthesis(n, open, close + 1, current + ")", result);
    }
}

int main(){
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    vector<string> result;

    generateParenthesis(n, 0, 0, "", result);

    for (const string& parentheses : result) {
        cout << parentheses << endl;
    }

    return 0;
}