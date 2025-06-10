//# The following is an O(nlogn) time, O(1) solution:
//# if there was no duplicate, the length of the array will be N. Not only 
//# that, if you pick any number 1<= x <= n, the numbers of elements in the array equal to or less than x will be x. 
//# If you pick two elements 1<= x < y <=N, then the number of elements in the array between x and y (both inclusive)
//# will be *(y-x+1). But if the duplicate is between x and y (both inclusive), then this rule will be
//# violated and the count will be (y-x+2). We have a sense of sorted order between x and y, 
//# which should make us think of a binary search over all such numbers like x and y. 
//# So consider the set of numbers [1,2,...N]. We have a left pointer, right pointer 
//# and a mid pointer. We count the number of elements in the given array that are (l, mid-1), that are 
//# equal to mid and that are (mid+1, r) (all inclusive). We check the condition diuscussed above
//# We exclude the half where the rule is not violated, and continue. 
//
//The above is unnecessarily complicated. if the number of array elementts < mid is > mid then 
// the duplicate is in the left half, as in smaller than mid. Otherwise it is larger than mid
//then 
//
//# Note a sort will also be O(nlogn) time and O(1) space but it will change the input array.
//
#include <iostream>
#include <vector>

class Solution{
	public:
		int findDuplicate_bs(std::vector<int> &nums){
			int left = 1;
			int right = nums.size() - 1;

			while (left<right){
				int mid = left + (right - left)/2;
				int count = 0;

				// count the numbers in nums less than or equal to mid
				for (int num:nums){
					if (num <= mid){
						count ++;
					}
				}
				if (count > mid){ // the number is in the left half - smaller than mid
					right = mid;
				} else { // The number is in the right half (greater than mid)
					 left = mid+1;
				}
			}
			return left;
		}

		int findDuplicate_floyd(std::vector<int> &nums){
			int slow = nums[0];
			int fast = nums[0];

			// Find the interesection pount of two pointers
			// note its do-while not while-do
			do {	
				// treat the array as a linked list. The number x at an index
				// is a pointer/link to the number which sits at the index x.  
				// 
				slow = nums[slow];
				fast = nums[nums[fast]];
			} while (slow != fast);

			// Find the entrance of the cycle
			slow = nums[0];
			while (slow != fast){

				slow = nums[slow];
				fast = nums[fast];
			}
			return slow;
		}

		int sumOfNums(std::vector<int> &nums){

			// The sum of numbers from 1 to n is n*(n+1)/2
			// The difference between this and the sum of the
			// numbers in the input is the duplicate number
			int n = nums.size() - 1;
			int targetSum = (n*(n+1))/2;
			int arraySum = 0;
			for (int num: nums)
				arraySum = arraySum + num;
			return (arraySum - targetSum);
		}

};

int main(){

	std::vector<int> nums = {3,1,3,4,2};
	std::vector<int> nums2 = {4,2,3,1,5,2};

	Solution sol;

	int duplicate1 = sol.findDuplicate_bs(nums2);
	int duplicate2 = sol.findDuplicate_floyd(nums2);
	int duplicate3 = sol.sumOfNums(nums2);

	std::cout << "Duplicate from binsearch: "<< duplicate1 << std::endl;
	std::cout << "Duplicate from Floyd: "<< duplicate2 << std::endl;
	std::cout << "Duplicate from sumOfNums: "<< duplicate3 << std::endl;

	return 0;
}




