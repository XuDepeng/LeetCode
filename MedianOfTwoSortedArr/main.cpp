#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <algorithm>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

// sad to copy from net, to implement by myself
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = static_cast<int>(nums1.size() + nums2.size());

		if (n % 2 == 1)
		    return findKth(nums1, 0, nums2, 0, n / 2 + 1);
		else
			return (findKth(nums1, 0, nums2, 0, n / 2) +
			findKth(nums1, 0, nums2, 0, n / 2 + 1)) / 2.0;
	}
private:
	int findKth(vector<int>& nums1, int b1, vector<int>& nums2, int b2, int k) {
		if (nums1.size() - b1 > nums2.size() - b2) {
			return findKth(nums2, b2, nums1, b1, k);
		}

		if (nums1.size() - b1 == 0) {
			return nums2.at(b2 + k - 1);
		}

		if (k == 1)
			return min(nums1[b1], nums2[b2]);

		int k1 = min(k / 2, (int)nums1.size() - b1), k2 = k - k1;
		if (nums1[b1 + k1 - 1] == nums2[b2 + k2 - 1])
			return nums1[b1 + k1 - 1];
		else if (nums1[b1 + k1 - 1] < nums2[b2 + k2 - 1])
		    return findKth(nums1, b1 + k1, nums2, b2, k - k1);
		else
		    return findKth(nums1, b1, nums2, b2 + k2, k - k2);
	}
};

int main() {
	printf("nums1:");
	string str;	
	getline(cin, str);

	stringstream ss;
	ss.str(str);

	vector<int> nums1, nums2;
	string sub;
	while (getline(ss,sub,',')) {
		nums1.push_back(atoi(sub.c_str()));
	}
	ss.clear();

	printf("nums2:");
	getline(cin, str);
	ss.str(str);
	while (getline(ss,sub,',')) {
		nums2.push_back(atoi(sub.c_str()));
	}

	Solution sl;
	double ret = sl.findMedianSortedArrays(nums1, nums2);
	printf("%.4f\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}