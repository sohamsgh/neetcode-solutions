#include <iostream>
#include <vector>

//Hint Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//
//You must write an algorithm that runs in O(n) time and without using the division operation.
//
//Example 1:
//
//Input: nums = [1,2,3,4] Output: [24,12,8,6] Example 2:
//
//Input: nums = [-1,1,0,-3,3] Output: [0,0,9,0,0]
//
//Think how you can efficiently utilize prefix and suffix products to calculate the product of all elements except self for each index. Can you pre-compute the prefix and suffix products in linear time to avoid redundant calculations?
//

class Solution{
	public:
		std::vector<int> prodxSelf(std::vector<int> &nums){
			int n = nums.size();
			std::vector<int> output(n);
			output[0] = 1;
			for (int i = 1; i < n; i++){
				output[i] = nums[i-1]*output[i-1];
				std::cout<< output[i]<<std::endl;
			}
			int result = 1;
			for (int i = n-1; i >=0; i--){
				output[i] = output[i]*result;
				result *= nums[i];
			}
			return output;
		}
};

int main(){
	Solution sol;
	std::vector<int> nums = {1,2,3,4};
        std::vector<int> output = sol.prodxSelf(nums); 
	for (int num:output){
		std::cout << num << ' ';
	}
	std::cout<<std::endl;
	return 0;
}




