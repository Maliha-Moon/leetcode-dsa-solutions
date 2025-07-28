#include<bits/stdc++.h>
using namespace std;

/**
 * Maximum Subarray Sum - Kadane's Algorithm
 * 
 * Difficulty: Easy
 * 
 * Problem Description:
 * Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 * 
 * Approach:
 * Implements Kadane's Algorithm which efficiently solves the problem in O(n) time:
 * 1. Iterate through the array while maintaining a running sum.
 * 2. Track the maximum sum encountered at each step.
 * 3. Reset the running sum to 0 if it becomes negative (indicating a better subarray can start from current position).
 * 
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(1) - Uses constant extra space
 * 
 * @param nums: vector of integers
 * @return: maximum sum of any contiguous subarray
*/

int maxSubArray(vector<int>& nums) {
    int sum = 0,maxNum = INT_MIN;
        for(int i=0; i<nums.size(); i++){
           sum += nums[i]; //-2 -3
           maxNum = max(maxNum,sum); //-2
           if(sum < 0) // 0
             {sum = 0;}
        }
        return maxNum;
    }

int main(){
    vector<int> a = {-2, -3, -7, -2, -10, -4};
    cout << maxSubArray(a) << '\n'; 
    return 0;
}

