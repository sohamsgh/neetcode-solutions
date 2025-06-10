////Search in Rotated Sorted Array Medium
//Topics Companies There is an integer array nums sorted in ascending order (with distinct values).
//
//Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
//
//Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
//
//You must write an algorithm with O(log n) runtime complexity.
//
//Example 1:
//
//Input: nums = [4,5,6,7,0,1,2], target = 0 Output: 4 Example 2:
//
//Input: nums = [4,5,6,7,0,1,2], target = 3 Output: -1 Example 3:
//
//Input: nums = [1], target = 0 Output: -1
//The idea is based on the fact that in a sorted and rotated array, if we go to mid, then either the left half would be sorted or 
//the right half 1 (both can also be sorted). For example, arr[] = [5, 6, 0, 1, 2, 3, 4], mid = 3 and 
//we can see that the subarray from mid + 1 to high is sorted. And in [5, 6, 7, 8, 9, 3, 4], we 
//can see that the subarray from low to mid-1 is sorted. We can check which half is sorted by comparing 
//arr[low] and arr[mid] (We could also compare arr[high] and arr[mid]). 
//
//
//Find the mid point. If key is same as the mid, return the mid.
//Find which half is sorted. If the key lies in the sorted half, move to that half. Otherwise move to the other half.
//Note that once we find which half is sorted, we can easily 
//check if the key lies here by checking if key lies in the range from smallest to largest in this half.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		int searchRot(vector<int> &nums, int target){

			int l = 0;
			int r = nums.size();
			while (l<r){
				int mid = l + (r-l)/2;
				if (target == nums[mid]){
					return mid;
				}
				if (nums[mid] > nums[r]){
					if ((nums[l] <=target) && (target <= nums[mid-1])){
						r = mid;
					} else {
						l = mid+1;
					}
				} else {
					if ((nums[mid+1] <=target) && (target <= nums[r])){
						l = mid + 1;
					} else {
						r = mid;
					}
				}
			}
			return l;
		}
};

int main(){

	Solution sol;

	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 0;
	cout<< sol.searchRot(nums, target) << endl;
	return 0;
}

				


				


