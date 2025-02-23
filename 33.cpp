
#include <iostream>
using namespace std;

int search(int nums[], int target, int size) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid]) {

            if (nums[left] <= target && target <= nums[mid]) right = mid - 1;

            else left = mid + 1;

        } else {

            if (nums[mid] <= target && target <= nums[right]) left = mid + 1;

            else right = mid - 1;

        }
    }

    return -1;
}

int main() {
    int a[7] = {4,5,6,7,0,1,2};
    int target = 0;

    cout << search(a, target, 7) << endl;

    return 0; 
}