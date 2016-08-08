/*
 * IntersectionOfTwoLinkedList.cpp
 *
 *  Created on: 2016年7月15日
 *      Author: weilongy
 */

#include <iostream>
#include "LinkedList.h"

#include <stack>
using namespace std;

//A:      a1	→	a2
//						↘
//						c1	→	c2	→	c3
//						↗
//B:b1	→	b2	→	b3
//
//return c1

ListNode* getIntersectionNode(ListNode* p, ListNode* q)
{
	if (!p || !q) return NULL;

	stack<ListNode*> s1;
	stack<ListNode*> s2;

	while (p) {
		s1.push(p);
		p = p->next;
	}
	while (q) {
		s2.push(q);
		q = q->next;
	}

	while (!s1.empty() && !s2.empty()) {
		if (s1.top() == s2.top()) {
			s1.pop();
			s2.pop();
		} else {
			break;
		}
	}
	return s1.top()->next;
}

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);

	ListNode* common = head->next->next;
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	ListNode* head2 = new ListNode(9);
	head2->next = new ListNode(8);
	head2->next->next = common;


	ListNode* commonStart = getIntersectionNode(head, head2);
	cout<<commonStart->val<<endl;

}
