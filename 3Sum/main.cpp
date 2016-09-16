#include <cstdlib>
#include <cstdio>

#include <vector>
#include <set>

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		if (0 == nums.size()){
			return ret;
		}

		sort(nums.begin(), nums.end());

		int cur = 0;
		while (cur < nums.size() && nums[cur] <= 0) {
			int rem = 0 - nums[cur];

			int l = cur + 1, r = (int)nums.size() - 1;
			while (l < r) {
				int sum = nums[l] + nums[r];

				if (sum > rem){
					r--;
				}

				else if (sum < rem){
					l++;
				}

				else{
					vector<int> temp;
					temp.push_back(nums[cur]);
					temp.push_back(nums[l]);
					temp.push_back(nums[r]);

					// it seems to cost a lot of time!
					// if (find(ret.begin(), ret.end(), temp) == ret.end()) {
					//	ret.push_back(temp);
					//}
					//}

					// skip same figures
					while (++l < r && nums[l] == nums[l - 1]);
					while (l < --r && nums[r] == nums[r + 1]);

					temp.clear();
					temp.shrink_to_fit();

					l++;
				}
			}
			cur++;
		}
		return ret;
	}
};

int main() {
	string str;
	getline(cin, str);

	stringstream ss;
	ss.str(str);

	vector<int> nums;
	string sub;
	while (getline(ss, sub, ',')){
		nums.push_back(atoi(sub.c_str()));
	}

	Solution sl;
	vector<vector<int>> ret = sl.threeSum(nums);

	system("puase");
	return EXIT_SUCCESS;
}