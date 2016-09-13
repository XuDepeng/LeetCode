#include <cstdlib>
#include <cstdio>

#include <string>
#include <sstream>

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

string longest_palindrome_manacher(string s) {
	return string();
}

int main() {
	string str;
	getline(cin, str);

	string ret = longest_palindrome_scan(str);

	printf("%s\n", ret.c_str());

	system("pause");
	return EXIT_SUCCESS;
}