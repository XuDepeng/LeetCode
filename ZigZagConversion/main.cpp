#include <cstdio>
#include <cstdlib>

#include <string>
#include <vector>

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

string convert(string s, int numRows) {
	vector<Node> ns(numRows * 2 - 2);
	for (int i = 0; i < numRows - 1; ++i) {
		Node node = { 1, &ns[i + 1] };
		ns[i] = node;
	}
	ns[numRows - 1] = Node{ -1, &ns[numRows] };

	for (int i = numRows; i < numRows * 2 - 3; ++i) {
		Node node = { -1, &ns[i + 1] };
		ns[i] = node;
	}
	ns[2 * numRows - 3] = Node{ -1, &ns[0] };

	vector<string> str_rows(numRows);
	Node pos = ns[0];
	int row = 0;

	str_rows[0].push_back(s[0]);
	for (int i = 1; i < s.length(); ++i) {
		row += pos.data;
		str_rows[row].push_back(s[i]);
		pos = *pos.next;
	}

	string ret;
	for (int i = 0; i < numRows; ++i) {
		ret += str_rows[i];
	}

	ns.clear();
	ns.shrink_to_fit();

	str_rows.clear();
	str_rows.shrink_to_fit();

	return ret;
}

int main() {
	string str;
	getline(cin, str);

	int n_row = 0;
	scanf_s("%d", &n_row);

	string ret = convert(str, n_row);
	printf("%s\n", ret.c_str());

	system("pause");
	return EXIT_SUCCESS;
}