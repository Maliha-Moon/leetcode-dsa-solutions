#include<bits/stdc++.h>
using namespace std;

/**
* Maximum Subarray Sum - Optimized Brute Force Approach
*
* Difficulty: Medium.
*
* Problem Description:
* Given an integer array nums, find the subarray with the largest sum, and return its sum.

* Approach:
* This optimized brute force approach reduces the time complexity by eliminating the innermost loop:
* 1. Outer loop (i): Iterates through each possible starting index of the subarray.
* 2. Inner loop (j): Iterates through each possible ending index (from i to end), while maintaining a running sum of the subarray nums[i..j].
* * The sum is updated incrementally by adding nums[j] in each iteration.
* * The maximum sum is updated whenever a new maximum is found.
*
* Time Complexity: O(n^2) - Two nested loops (improved from O(n^3) in the pure brute force approach)
* Space Complexity: O(1) - Uses constant extra space
*
* @param nums: vector of integers
* @return: maximum sum of any contiguous subarray
*/

int maxSubArray(vector<int>& nums) {
    int sum,maxNum = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                maxNum = max(maxNum,sum); 
            }
        }
        return maxNum;
    }

int main(){
    vector<int> a = {-2, -3, -7, -2, -10, -4};
    cout << maxSubArray(a) << '\n'; 
    return 0;
}

