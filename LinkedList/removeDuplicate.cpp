/*
 * removeDuplicate.cpp
 *
 *  Created on: 2016年7月15日
 *      Author: weilongy
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;


/*remove duplicate from sorted linked list
 *
 */

ListNode* removeDuplicate(ListNode* head)
{
	if (head == NULL || head->next == NULL) return head;

	ListNode* cur = head;
	while (cur) {
		ListNode* first = cur;
		cur = cur->next;
		while (cur && (first->val == cur->val)) {
			ListNode* tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		first->next = cur;  //important
	}
	return head;
}

/*Given	a	sorted	linked	list,	delete	all	nodes	that	have	duplicate	numbers,	leaving	only	distinct
numbers	from	the	original	list.
 *
 * */
ListNode* removeAllDuplicate(ListNode* head)
{
	if (head == NULL || head->next == NULL) return head;

	ListNode dummy(0);
	dummy.next = head;
	ListNode* pre = &dummy;
	ListNode* cur = head;

	while (cur && cur->next) {
		if (cur->val == cur->next->val) {
			int val = cur->val;
			ListNode* nn = cur->next->next;
			while (nn) {
				if (val != nn->val) {
					break;
				}
				nn = nn->next;
			}
			pre->next = nn;
			cur = nn;

		} else {
			pre = cur;
			cur = cur->next;
		}
	}

	return dummy.next;

}

int main()
{
	ListNode* l1 = CreateList();
	l1 = removeDuplicate(l1);
	ListNode* l2 = CreateList();
	l2 = removeAllDuplicate(l2);
	PrintList(l2);
}
