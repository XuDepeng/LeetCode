#include <cstdlib>
#include <cstdio>

#include <string>
#include <stack>
#include <map>

#include <iostream>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.size() % 2) {
			return false;
		}

		map<char, int> m = {
			pair<char, int>('(', 0),
			pair<char, int>(')', 1),
			pair<char, int>('[', 2),
			pair<char, int>(']', 3),
			pair<char, int>('{', 4),
			pair<char, int>('}', 5),
		};

		stack<char> sc;

		for (int i = 0; i < s.size(); ++i) {
			if (m[s[i]] % 2 == 0) {
				sc.push(s[i]);
			}
			else {
				if (sc.empty()) {
					return false;
				}

				if (m[s[i]] - m[sc.top()] == 1) {
					sc.pop();
				}
				else
					return false;
			}
		}

		return sc.empty();
	}
};

int main() {
	string str;
	getline(cin, str);

	Solution sl;
	sl.isValid(str);

	return EXIT_SUCCESS;
}