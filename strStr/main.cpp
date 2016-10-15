#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int l1 = haystack.size(), l2 = needle.size();
		for (int i = 0, j; i <= l1 - l2; ++i) {
			for (j = 0; j < l2 && haystack[i + j] == needle[j]; ++j);
			if (j == l2)
				return i;
		}
		return -1;;
	}
};

int main() {
	string haystack, needle;
	cin >> haystack >> needle;

	Solution sl;
	int pos = sl.strStr(haystack, needle);

	return 0;
}