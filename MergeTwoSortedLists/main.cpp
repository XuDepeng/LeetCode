#include <cstdlib>
#include <cstdio>

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* h = new ListNode(0);

		ListNode* node = h;
		ListNode* n1 = l1;
		ListNode* n2 = l2;

		while (n1 && n2) {
			if (n1->val < n2->val) {
				ListNode* tmp = n1;
				n1 = n1->next;
				tmp->next = nullptr;
				node->next = tmp;
			}

			else {
				ListNode* tmp = n2;
				n2 = n2->next;
				tmp->next = nullptr;
				node->next = tmp;
			}

			node = node->next;
		}

		if (n1) {
			node->next = n1;
		}

		if (n2) {
			node->next = n2;
		}

		return h->next;
	}
};

int main() {
	return EXIT_SUCCESS;
}