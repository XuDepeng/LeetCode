#include <cstdlib>
#include <cstdio>

#include <string>
#include <sstream>
#include <iostream>

#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* h = new ListNode(0);
		h->next = head;

		ListNode* f = h;
		while (n--) {
			f = f->next;
		}

		ListNode* s = h;
		while (f->next) {
			f = f->next;
			s = s->next;
		}

		s->next = s->next->next;
		return h->next;
	}
};

int main() {
	string str;
	getline(cin, str);

	stringstream ss;
	ss.str(str);

	string sub;
	int n_node = 0;
	vector<ListNode*> nodes;
	while (getline(ss, sub, ',')) {
		ListNode* node = new ListNode(atoi(sub.c_str()));
		nodes.push_back(node);
	}

	for (int i = 0; i < nodes.size() - 1; ++i) {
		nodes[i]->next = nodes[i + 1];
	}
	nodes[nodes.size() - 1]->next = nullptr;

	int n = 0;
	scanf_s("%d", &n);

	Solution sl;
	ListNode* node = sl.removeNthFromEnd(nodes.front(), n);

	do {
		printf("%d\n", node->val);
		node = node->next;
	} while (node);

	system("pause");
	return EXIT_SUCCESS;
}