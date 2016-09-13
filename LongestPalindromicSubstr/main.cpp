#include <cstdlib>
#include <cstdio>

#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

string longest_palindrome_simple(string s) {
	string longest_str;
	for (int i = 0; i < s.length(); ++i) {
		for (int j = i; j < s.length(); ++j) {
			int sub_len = j - i + 1;
			if (sub_len < longest_str.length()) {
				continue;
			}

			string sub = s.substr(i, sub_len);
			string reverve_sub = sub;
			reverse(reverve_sub.begin(), reverve_sub.end());
			if (strcmp(sub.c_str(), reverve_sub.c_str()) == 0) {
				longest_str = sub;
			}
		}
	}
	return longest_str;
}

string longest_palindrome_scan(string s) {
	string longest_str;
	for (int i = 0; i < 2 * s.length() - 1; ++i) {
		int l = 0, r = 0;
		if (i % 2 == 0)
			l = i / 2 , r = i / 2;
		else
			l = i / 2 , r = i / 2 + 1;

		while (s[l] == s[r]) {
			if (r - l + 1 > longest_str.length())
				longest_str = s.substr(l, r - l + 1);

			l--;
			r++;

			if (l < 0 && r >= longest_str.length())
				break;
		}
	}
	return longest_str;
}

string pre_process(string s) {
	int n = (int)s.length();
	if (n == 0) return "^$";
	string ret = "^";
	for (int i = 0; i < n; i++)
		ret += "#" + s.substr(i, 1);

	ret += "#$";
	return ret;
}

string longest_palindrome_manacher(string s) {
	string T = pre_process(s);
	int n = (int)T.length();
	vector<int> P(n);
	int C = 0, R = 0;
	for (int i = 1; i < n - 1; i++) {
		int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

		P[i] = (R > i) ? std::min(R - i, P[i_mirror]) : 0;

		// attempt to expand palindrome centered at i
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;

		// if palindrome centered at i expand past R,
		// adjust center based on expanded palindrome.
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}

	// find the maximum element in P.
	vector<int>::iterator max_val = std::max_element(P.begin(), P.end());
	int cen_idx = (int)distance(P.begin(), max_val);

	return s.substr((cen_idx - 1 - *max_val) / 2, *max_val);
}

int main() {
	string str;
	getline(cin, str);

	string ret = longest_palindrome_manacher(str);

	printf("%s\n", ret.c_str());

	system("pause");
	return EXIT_SUCCESS;
}