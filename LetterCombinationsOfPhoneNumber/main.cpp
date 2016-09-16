#include <cstdlib>
#include <cstdio>

#include <iostream>

#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
	vector<string> m_ret;
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())	{
			return m_ret;
		}

		map<int, string> m = {
			pair<int, string>(0, ""),
			pair<int, string>(1, ""),
			pair<int, string>(2, "abc"),
			pair<int, string>(3, "def"),
			pair<int, string>(4, "ghi"),
			pair<int, string>(5, "jkl"),
			pair<int, string>(6, "mno"),
			pair<int, string>(7, "pqrs"),
			pair<int, string>(8, "tuv"),
			pair<int, string>(9, "wxyz"),
		};

		letterCombinations("", digits, 0, m);

		return m_ret;
	}
private:
	void letterCombinations(string s, string digits, int pos, map<int, string> m){
		if (pos >= digits.size()) {
			m_ret.push_back(s);
			return;
		}

		int num = atoi(digits.substr(pos, 1).c_str());
		string a = m[num];
		for (int i = 0; i < a.size(); ++i) {
			letterCombinations(s + a[i], digits, pos + 1, m);
		}
	}
};

int main(){
	string str;
	cin >> str;

	Solution sl;
	sl.letterCombinations(str);

	return EXIT_SUCCESS;
}