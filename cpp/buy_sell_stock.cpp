#include <iostream>
#include <vector>
////Leetcode Best Time to Buy and Sell Stock
//
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//
//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
//
//Example 1:
//
//Input: prices = [7,1,5,3,6,4] Output: 5 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell. Example 2:
//
//Input: prices = [7,6,4,3,1] Output: 0 Explanation: In this case, no transactions are done and the max profit = 0.
//
//
// There are several observations. The best time to buy has to come before the best time to sell. This
// indicates a two-pointer solution. 
//
// The best sell is the best sell of all best sells, as in, the maximum value of best sells for all possible days. 
// This suggests we dont need an array to hold the best sell for each day. Similar thoughts for best buy day. 
//
//We dont need a pointer for the sell since we dont bneed to return the buy and sell dates, only the best value. We need only one pointer

// Consider a pointer at the beginning of the array. It follows the day (so, the index i), and a scalar variable  stores the minimum value of the stock 
// till day i (call it min_i), we can use a number to store (price[i] - min_i). if price[i] becomes less than min_i, we will reset min_i to price_i
//
//
//
class Solution{
	public:
		int maxProfit1(std::vector<int> &prices){

			int min = prices[0];
			int max = 0;
			
			for (int i = 0; i < prices.size(); i++){
				// min stores the minimum value yet encountered
				if (prices[i] < min){
					min = prices[i];
				}else{
					// subtract the current price from the minimum value yet encountered
					// keep it in max, update it if you find a bigger value.
					if (prices[i] - min > max){
						max = prices[i] - min;
					}
				}
			}
			return max;
		}
};

int main(){
	//std::vector<int> prices ={7,1,5,3,6,4};
	std::vector<int> prices ={7,6,4,3,1};
	Solution sol;
        int maxprof = sol.maxProfit1(prices);
	std::cout<< "Msximum profit: "<<maxprof << std::endl;

	return 0;
}



