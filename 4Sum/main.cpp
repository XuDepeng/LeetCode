#include <cstdlib>
#include <cstdio>

#include <vector>
#include <string>
#include <sstream>

#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> ret;

		int i = 0;
		while (i < nums.size()) {
			int j = i + 1;
			while (j < nums.size()) {
				int l = j + 1, r = (int)nums.size() - 1;

				int rem = target - nums[i] - nums[j];

				while (l < r) {
					int sum = nums[l] + nums[r];
					if (sum > rem) {
						r--;
					}
					else if (sum < rem) {
						l++;
					}
					else {
						ret.push_back({ nums[i], nums[j], nums[l], nums[r] });
						// skip same figures
						while (++l < r && nums[l] == nums[l - 1]);
						while (l < --r && nums[r] == nums[r + 1]);
					}
				}
				while (++j < nums.size() && nums[j] == nums[j - 1]);
			}
			while (++i < nums.size() && nums[i] == nums[i - 1]);
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
	while (getline(ss, sub, ',')) {
		nums.push_back(atoi(sub.c_str()));
	}

	int target = 0;
	scanf_s("%d", &target);

	Solution sl;
	sl.fourSum(nums, target);

	system("pause");
	return EXIT_SUCCESS;
}