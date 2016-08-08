/*
 * LinkedListCycle.cpp
 *
 *  Created on: 2016年7月15日
 *      Author: weilongy
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;



bool hasCycle(ListNode* head)
{
	if (head == NULL || head->next == NULL) return false;
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return true;
	}

	return false;
}


//	   1    ->    2    ->    3      ->
//	              |                     |
//	              6    <-    5    <-    4
//上面这个链表，fast和slow会在节点6相遇， fast走的路程是slow的2倍。设1到2的距离为a, 2到6的距离为b，6到2的距离为c
//那么a走了 a + b + c + b
//b走了  a + b
//所以， a+ b+ c+b = 2(a+b)
//所以，a = c

ListNode* detectCycleNode(ListNode* head)
{
	if (head == NULL || head->next == NULL) return head;

	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* p = head;
	ListNode* q = NULL;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			q = fast;
			cout<<"Encounter at:"<<q->val<<endl;
			break;
		}
	}

	while (p != q) {
		p = p->next;
		q = q->next;
	}
	return p;
}


int main()
{

//	   1    ->    2    ->    3      ->
//	              |                     |
//	              6    <-    5    <-    4

	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	ListNode* tmp = head->next;
	head->next->next = new ListNode(3);

	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = tmp;

//	cout<<hasCycle(head)<<endl;

	ListNode* node = detectCycleNode(head);
	cout<<"The first node in the cycle:"<<node->val<<endl;

}

