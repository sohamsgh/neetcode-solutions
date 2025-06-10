//Maximum Subarray
//
//Medium
//
//Topics Companies Given an integer array nums, find the subarray with the largest sum, and return its sum.
//
//Example 1:
//
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4] Output: 6 Explanation: The subarray [4,-1,2,1] has the largest sum 6. Example 2:
//
//Input: nums = [1] Output: 1 Explanation: The subarray [1] has the largest sum 1. Example 3:
//
//Input: nums = [5,4,-1,7,8] Output: 23 Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
//
// Solution - II (Recursive) [TLE] - explanation copied from Abhishek

//Another way to consider every subarray and return the one that has maximum 
//sum is using recursive approach. Here we can state the approach as -
//
////At each index i, we can either pick that element or not pick it.
////If we pick current element, then all future element must also be picked since our array needs to be contiguous.
//If we had picked any elements till now, we can either end further recursion at any 
//time by returning sum formed till now or we can choose current element and 
//recurse further. This denotes two choices of either choosing the subarray 
//formed from 1st picked element till now or expanding the subarray by choosing current element respectively.
//In the code below, we will use mustPick to denote whether we must compulsorily pick 
//current element. When mustPick is true, we must either return 0 or pick current element 
//and recurse further. If pickCur is false, we have both choices of not picking 
//current element and moving on to next element, or picking the current one.
//
#include<iostream>
#include<vector>

class Solution{
	public:
		int maxSubArrayRec1(std::vector<int> &nums){
			return solve(nums, 0, false);
		}
		int solve(std::vector<int> &A, int i, bool mustPick){
			// Our subarray must contain at least one element
			// if mustPick is false at the end it means no element is 
			// picked and this is not valid
			if (i >= A.size()) return mustPick ? 0: 1e-05;
			if (mustPick){
				return max(0, solve(A, i+1, true));// Either stop here or choose current element and recurse
			}
			return max(solve(A, i+1, false), A[i] + solve(A, i+1, true));
		}



		int kadane(std::vector<int> &nums){

			int maxsum = nums[0];
			int maxglob = nums[0];
			for (int i = 1; i< nums.size(); i++){
				if (nums[i] > (nums[i] + maxsum)){
					maxsum = nums[i];
				} else {
					maxsum = nums[i] + maxsum;
				}
				if (maxglob < maxsum) {
					maxglob = maxsum;
				}

			}
			return maxglob;
		}
};

int main(){

	std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

	Solution sol;

	std::cout << "Max Subarray value: "<< sol.kadane(nums) << std::endl;

	return 0;
}
