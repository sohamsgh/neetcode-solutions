#include <iostream>
#include <vector>

class Solution {
	public:
		int prodKadane(std::vector<int> &nums) {

			int curmax = nums[0];
			int curmin = nums[0];
			int glomax = nums[0];

			for (int i = 1; i < nums.size(); i++) {
				curmax = std::max({nums[i], nums[i]*curmax, nums[i]*curmin});
				curmin = std::min({nums[i], nums[i]*curmax, nums[i]*curmin});
				if (curmax > glomax) {
					glomax = curmax;
				}
			}
			return glomax;
		}
		
};

int main() {

	std::vector<int> nums = {2,3,-2,4};
        Solution S;
	int maxProd = S.prodKadane(nums);
	std::cout<<maxProd <<"\n";

	return 0;
}

