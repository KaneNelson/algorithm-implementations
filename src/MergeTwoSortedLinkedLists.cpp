#include<iostream>
#include <string>
using namespace	std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class mergeTwoLinkedLists {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* head = new ListNode;
		ListNode* ptr1 = list1;
		ListNode* ptr2 = list2;
		ListNode* ptr3 = head;

		while (ptr1 != nullptr || ptr2 != nullptr) {
			if (ptr1 == nullptr) {
				ptr3->val = ptr2->val;
				ptr3 = ptr3->next;
			}
			else if (ptr2 == nullptr) {
				ptr3->val = ptr1->val;
				ptr3 = ptr3->next;
			}
			else if (ptr1->val > ptr2->val) {
				ptr3->val = ptr2->val;
				ptr2 = ptr2->next;
				ptr3 = ptr3->next;
			}
			else if (ptr1->val <= ptr2->val) {
				ptr3->val = ptr1->val;
				ptr1 = ptr1->next;
				ptr3 = ptr3->next;
			}
		}




	}
};




