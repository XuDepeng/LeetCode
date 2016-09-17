#include <cstdlib>

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

		ListNode* n1 = l1;
		ListNode* n2 = l2;
	}
};

int main() {
	return EXIT_SUCCESS;
}