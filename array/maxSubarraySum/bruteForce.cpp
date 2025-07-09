#include<bits/stdc++.h>
using namespace std;

/**
 * Maximum Subarray Sum - Brute Force Approach 
 * 
 * Difficulty: Medium.
 * 
 * Problem Description:
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * 
 * Approach:
 * Brute force checks all possible contiguous subarrays using three nested loops:
 * 1. Outer loop (i): Iterates through each possible starting index of the subarray.
 * 2. Middle loop (j): Iterates through each possible ending index (from i to end).
 * 3. Inner loop (k): Computes the sum of the subarray nums[i..j] by iterating from i to j.
 * 
 * Time Complexity: O(n^3) - Three nested loops
 * Space Complexity: O(1) - Uses constant extra space
 * 
 * @param nums: vector of integers
 * @return: maximum sum of any contiguous subarray
 */

int maxSubArray(vector<int>& nums) {
    int sum,maxNum = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                sum = 0;
                for(int k=i; k<=j; k++){
                    sum += nums[k];
                   maxNum = max(maxNum,sum);
                }
            }
        }
        return maxNum;
    }

int main(){
    vector<int> a = {-2, -3, -7, -2, -10, -4};
    cout << maxSubArray(a) << '\n'; 
    return 0;
}

