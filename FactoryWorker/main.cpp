#include <iostream>

#include <list>

#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int Te = 0;
	cin >> Te;
	for (int i = 0; i < Te; ++i) {
		int n = 0;
		cin >> n;
		list<string> usr_id;

		list<string> str_lst;
		stringstream ss;
		string str;

		for (int i = 0; i < n; ++i) {
			cin >> str;
			str_lst.push_back(str);
		}

		copy(str_lst.begin(), str_lst.end(), ostream_iterator<string>(ss, " "));
		str_lst.clear();

		while (ss >> str) {
			usr_id.push_back(str);
		}
		ss.clear();

		for (int i = 0; i < n - 1; ++i) {
			cin >> str;
			str_lst.push_back(str);
		}

		copy(str_lst.begin(), str_lst.end(), ostream_iterator<string>(ss, " "));
		str_lst.clear();

		while (ss >> str) {
			usr_id.remove(str);
		}

		printf("%s\n", usr_id.front().c_str());

		str_lst.clear();
		usr_id.clear();
	}

	system("pause");
	return 0;
}