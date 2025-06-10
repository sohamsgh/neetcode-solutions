#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int rotSortMin(std::vector<int> &nums) {

			int left = 0;
			int right = nums.size() - 1;
                        int mid; 
			while (left < right) {
				mid = left + (right - left)/2;

				if (nums[mid] > nums[right]) {
					// the minumum is in the right half
					left = mid + 1;
				} else {
					// The minimum is in the left half
					right = mid;
				}
			}
			return nums[mid];
		}
};


int main(){

	std::vector<int> nums = {3,4,5,1,2};
	Solution S;

	int minval = S.rotSortMin(nums);

	cout<< minval<<"\n";
	return 0;
}





			

