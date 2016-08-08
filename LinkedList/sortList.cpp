/*
 * sortList.cpp
 *
 *  Created on: 2016年8月8日
 *      Author: weilongy
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;

ListNode* merge(ListNode* p1, ListNode* p2);

ListNode* sortList(ListNode* head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode* fast = head;
	ListNode* slow = head;

	while (fast && fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = slow->next;
	slow->next = NULL;

	ListNode* p1 = sortList(head);
	ListNode* p2 = sortList(fast);
	return merge(p1, p2);
}

/*
 * merge two list, sort from small to large
 * */
ListNode* merge(ListNode* p1, ListNode* p2)
{
	if (p1 == NULL) {
		return p2;
	} else if (p2 == NULL) {
		return p1;
	} else if (p1 == NULL && p2 == NULL) {
		return NULL;
	}

	ListNode dummy(0);
	ListNode* p = &dummy;

	while (p1 && p2) {
		if (p1->val < p2->val) {
			p->next = p1;
			p1 = p1->next;
		} else {
			p->next = p2;
			p2 = p2->next;
		}
		p = p->next;
	}

	if (p1 == NULL) {
		p->next = p2;
	} else if (p2 == NULL) {
		p->next = p1;
	}
	return dummy.next;
}

int main()
{
	ListNode* p =  CreateList();
	p = sortList(p);
	PrintList(p);

}

