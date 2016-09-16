#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <algorithm>

#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (3 > nums.size()){
			return 0;
		}

		sort(nums.begin(), nums.end());

		int closest = nums[0] + nums[1] + nums[2];

		int cur = 0;
		while (cur < nums.size()){
			int l = cur + 1, r = (int)nums.size() - 1;
			while (l < r) {
				int sum = nums[cur] + nums[l] + nums[r];
				if (abs(sum - target) < abs(closest - target)){
					closest = sum;
				}

				if (sum == target) {
					return target;
				}
				else if (sum < target){
					l++;
				}
				else
					r--;
			}
			cur++;
		}

		return closest;
	}
};

int main(){
	string str;
	getline(cin, str);

	stringstream ss;
	ss.str(str);

	vector<int> nums;
	string sub;
	while (getline(ss, sub, ',')){
		nums.push_back(atoi(sub.c_str()));
	}
	ss.clear();

	int target = 0;
	scanf_s("%d", &target);

	Solution sl;
	int ret = sl.threeSumClosest(nums, target);
	printf("%d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}