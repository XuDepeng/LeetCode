#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <algorithm>

#include <string>
#include <set>

int len_of_substr_simple(const std::string& str) {
	int max_len = 1;
	for (int i = 0; i < str.size(); ++i) {
		for (int j = i + 1; j < str.size(); ++j) {
			std::string sub = str.substr(i, j - i + 1);
			std::set<char> ch_set;
			bool flag = false;

			for (int k = 0; k < sub.size(); ++k) {
				if (ch_set.find(sub.at(k))!=ch_set.end()) {
					flag = true;
					break;
				}
				ch_set.insert(sub.at(k));
			}
			ch_set.clear();

			if (flag) {
				break;
			}
			max_len = std::max(j - i + 1, max_len);
		}
	}

	return max_len;
}

int len_of_substr_hash(const std::string& str) {
	int max_len = 1;
	int l = 0, r = 0;

	std::set<char> cset;

	while (r < str.size()) {
		if (cset.find(str[r]) == cset.end()) {
			cset.insert(str[r]);
		}
		else {
			max_len = std::max(r - l, max_len);
			while (str[r] != str[l]) {
				cset.erase(str[l]);
				++l;
			}
			++l;
		}
		++r; // next char
	}
	cset.clear();

	max_len = std::max(max_len, r - l);
	return max_len;	
}

int main() {
	printf("string:");
	std::string str;
	std::getline(std::cin, str);

	int len = len_of_substr_hash(str);
	printf("%d\n", len);

	system("pause");
	return EXIT_SUCCESS;
}