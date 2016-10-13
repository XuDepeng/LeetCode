#include <cstdio>
#include <cstdlib>

#include <string>
#include <vector>

#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		int l = n, r = n;
		generateParenthesis("", l, r);

		return ret;
	}

private:
	void generateParenthesis(string s, int l, int r) {
		if (r == 0) {
			ret.push_back(s);
			return;
		}

		if (l < r) {
			generateParenthesis(s + ')', l, r - 1);
		}

		if (l > 0) {
			generateParenthesis(s + '(', l - 1, r);
		}

	}

private:
	vector<string> ret;
};

int main() {
	int n = 0;
	scanf_s("%d", &n);

	Solution sl;
	sl.generateParenthesis(n);

	return EXIT_SUCCESS;
}