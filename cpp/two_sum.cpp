#include<iostream>
#include<vector>
//Leetcode two sum
//
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.
//
//Example 1:
//
//Input: nums = [2,7,11,15], target = 9 Output: [0,1] Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]. Example 2:
//
//Input: nums = [3,2,4], target = 6 Output: [1,2] Example 3:
//
//Input: nums = [3,3], target = 6 Output: [0,1]
//
//
// Brute force: Two nested loops, each over the array
//
class Solution1{
	public:
		std::vector<int> twoSum(std::vector<int> &nums, int target){
			for (int i = 0; i < nums.size(); i++){
				for (int j = 0; j < nums.size(); j++){
					if ((i != j) && ((nums[i] + nums[j]) == target)){
						return {i,j};
					}
				}
			}
			return {};
		}
};

// Method 2: Two pass with a hash map. Crrate the hash in the first pass, go over it in the second.
//
class Solution2{
	public:
		std::vector<int> twoSum(std::vector<int> &nums, int target){
			std::unordered_map<int, int> numMap;

			for (int i = 0; i < nums.size(); i++){
				numMap[nums[i]] = i;
			}
			for (int i = 0; i < nums.size(); i++){
				int compliment = target - nums[i];
				if (numMap.count(compliment) && (numMap[compliment] !=i )){
						return {i,numMap[compliment]};
						}
			}
			return {};
		}
};

// One pass hash map. We check while cresting the map. Note some subtlety:
// Say x+y = target where x,y belongs to nums. When cresting the map, if we
// encounter x first, the check will ne negative and x will be added to the map. When 
// encounter y, the check will succeed. 
//
// However, what if the condition was x-y = target?
//
// That cab be written as 1) x = target -y, or 2) y = x - target
//
// For 1), we check if (target - nums[i] exists in map)
// For 2), we check if (nums[i] - target exists in map). 

//If we choose 1), and y has a lower index than x in the array, then x isnt in the map when we check the 
//condition with y, and the check will fail, but option 2) will succeed since y will be in the map. 
//The reverse is true if x has a lower index than y.
//Example: x-y = target, x = 10, y = 4, target = 6. If x comes before y in the array, 
//Is (x-target) in map)? check will fail. but if the array is sorted in increasing order, 
//then 4 is guaranteed to be in the map before 10, and the chjeck will succeed. 
//
//To do the one-pass method, we will either need a condition which is symettric wrt to the arguments (x+y), 
//or have an idea about the order of the array. If the array is sorted, we know which option to choose among 1) and 2), 

class Solution3{
	public:
		std::vector<int> twoSum(std::vector<int> &nums, int target){
			std::unordered_map<int, int> numMap;

			for (int i = 0; i < nums.size(); i++){
				if (numMap.count(target-nums[i])){
					return {i, numMap[target-nums[i]]};
				}
				numMap[nums[i]] = i;
			}
			return {};
		}
};

// Driver code
int main(){
	std::vector<int> nums = {2,7,11,15};
	int target = 9;

	Solution1 sol1;
	Solution2 sol2;
	Solution3 sol3;

	std::vector<int> result1 = sol1.twoSum(nums, target);
	std::vector<int> result2 = sol2.twoSum(nums, target);
	std::vector<int> result3 = sol3.twoSum(nums, target);

	for (int i: result1){
		std::cout << i << ' ';
	}
	std::cout<<std::endl;
	for (int i: result2){
		std::cout << i << ' ';
	}
	std::cout<<std::endl;
	for (int i: result3){
		std::cout << i << ' ';
	}
	std::cout<<std::endl;
	return 0;
}

