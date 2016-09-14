#include <cstdlib>
#include <cstdio>

#include <iostream>

#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> m = {
			pair<char, int>('M', 1000),
			pair<char, int>('D', 500),
			pair<char, int>('C', 100),
			pair<char, int>('L', 50),
			pair<char, int>('X', 10),
			pair<char, int>('V', 5),
			pair<char, int>('I', 1),
		};

		int ret = 0;
		int cur_val = 0, pre_val = 0;

		for (string::reverse_iterator iter = s.rbegin(); iter != s.rend(); ++iter) {
			cur_val = m[*iter];
			if (cur_val < pre_val) {
				ret += -cur_val;
			}
			else {
				ret += cur_val;
			}
			pre_val = cur_val;
		}

		m.clear();
		return ret;
	}
};

int main() {
	string str;
	getline(cin, str);

	Solution sl;
	int ret = sl.romanToInt(str);

	printf("%d\n", ret);
	system("pause");
	return EXIT_SUCCESS;
}