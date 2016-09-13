#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <algorithm>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

int max_area(vector<int>& height) {
	int l = 0, r = (int)height.size() - 1;
	int ret = 0;

	while (l < r) {
		ret = max(ret, min(height[l], height[r]) * (r - l));
		if (height[l] < height[r]) {
			l++;
		}
		else {
			r--;
		}
	}

	return ret;
}

int main() {
	string str;
	getline(cin, str);

	stringstream ss;
	ss.str(str);

	vector<int> height;
	string sub;
	while (ss >> sub) {
		height.push_back(atoi(sub.c_str()));
	}

	printf("%d\n", max_area(height));

	system("pause");
	return EXIT_SUCCESS;
}