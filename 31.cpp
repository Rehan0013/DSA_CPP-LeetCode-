//--------------LeetCode 31

// Next Permutation
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].

#include<iostream>
using namespace std;

void nextPermutation(int nums[], int size) {
        int pv = -1, n = size;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pv = i;
                break;
            }
        }

        if(pv == -1) {
            for(int i = 0; i < n/2; i++) {
                int temp = nums[i];
                nums[i] = nums[n - 1];
                nums[n - 1] = temp;
            }
            return;
        }

        for(int i = n - 1; i > pv; i--) {
            if(nums[i] > nums[pv]) {
                swap(nums[i], nums[pv]);
                break;
            }
        }

        int i = pv + 1, j = n - 1;
        while(j > i) {
            swap(nums[i++], nums[j--]);
        }

    }

int main() {
    int a[3] = {1, 2, 3};

    nextPermutation(a, 3);

    for(int i = 0; i < 3; i++) 
        cout << a[i] << " ";
    
    cout << endl;

    return 0;
}