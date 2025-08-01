#include<bits/stdc++.h>
using namespace std;

/**
 * Best Time to Buy and Sell Stock 
 * 
 * Difficulty: Easy
 * 
 * Problem Description:
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0
 * 
 * Approach:
 * 1. Initialize `mini` with the first price and `profit` with 0 (minimum possible profit).
 * 2. Iterate through the prices array:
 *    - Calculate potential profit if sold at current price (current price - `mini`)
 *    - Update `profit` if current potential profit is greater
 *    - Update `mini` if current price is lower than existing `mini`
 * 3. Return the maximum profit found.
 * 
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(1) - Uses constant extra space
 * 
 *  @param prices Vector of daily stock prices
 * @return Maximum achievable profit
 */

int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0,cost ;
        for(int i=0; i<prices.size(); i++){
           cost = prices[i] - mini;
           profit = max(profit,cost);
           mini = min (mini, prices[i]);
        }
  return profit;
    }

int main(){
     vector<int> a = {7,6,4,3,1};
    cout << maxProfit(a) << '\n';
    return 0;
}