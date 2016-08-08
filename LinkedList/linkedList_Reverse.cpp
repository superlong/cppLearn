/*
 * linkedList_Reverse.cpp
 *
 *  Created on: 2016年7月15日
 *      Author: weilongy
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;



/*例如以下链表，反转2,3,4
 * 1->2->3->4->5
 * pre = 1  前驱节点
 * end = 5,
 * */
ListNode* ReverseBetweenNodes(ListNode* pre, ListNode* end)
{
	if (pre == NULL || pre->next == NULL) return pre;

	ListNode* cur = pre->next; //作为位移节点，向右移

	/* 1    ->    2    ->    3    ->    4    ->    5
	 * pre        cur        pNext
	 * step 1:
	 * 1    ->    3    ->    2    ->    4    ->    5
	 * pre                   cur
	 *
	 * step 2：
	 * 1    ->    3    ->    2    ->    4    ->    5
	 * pre                              cur
	 * */
	while (cur->next != end) {
		ListNode* pNext = cur->next;  //保存下一个节点
		cur->next = pNext->next; //移动cur->next指向下一个元素，用cur->next判断是否到达end
		pNext->next = pre->next; //让第二个节点 指向 前一个 节点
		pre->next = pNext; //更新pre->next， pre指向第二个节点
	}
	return cur;
}

ListNode* ReverseKGroup(ListNode* head, int k)
{
	if (head == NULL || k <= 1) return head;

	ListNode dummy(0);
	dummy.next = head;
	ListNode* p = &dummy;
	ListNode* pre = NULL;

	while (p) {
		//找到第k个节点
		pre = p; //更新pre节点， pre节点是需要反转部分的前驱节点
		for (int i = 0; i < k; i++) {
			p = p->next;
			if (p == NULL) {
				return dummy.next;
			}
		}
		//更新p节点为 下一组需要反转的k个链表的 前驱节点
		p = ReverseBetweenNodes(pre, p->next);
	}

	return dummy.next;
}

/*原链表 , m = 2, n = 4
 * 1    ->    2    ->    3    ->    4    ->    5
 *转换后：
 * 1    ->    4    ->    3    ->    2    ->    5
 * */
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (head == NULL || head->next == NULL) return head;
	ListNode dummy(0);
	dummy.next = head;
	ListNode* p = &dummy;

	for (int i = 1; i < m; i++) {
		p = p->next;
	}
	cout<<"m:"<<p->val<<endl;

	ListNode* pre = p; //作为前驱节点
	ListNode* cur = pre->next;

	for (int i = m; i < n; i++) {
		ListNode* pNext = cur->next;
		cur->next = pNext->next;
		pNext->next = pre->next;
		pre->next = pNext;
	}
	return dummy.next;

}

/*
 * Reverse a singly linked list.
 * */
ListNode* ReverseList(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* prev = NULL;
	ListNode* pNode = head;

	while (pNode) {
		ListNode* pNext = pNode->next;
		pNode->next = prev;
		prev = pNode;
		pNode = pNext;
	}
	return prev;
}


int main()
{
	//create list
	ListNode* l1 = CreateList();

	//test for reverseBetween
	int m, n;
	cout<<"input m:";
	cin>>m;
	cout<<"input n:";
	cin>>n;
	l1 = reverseBetween(l1, m, n);
	PrintList(l1);

	//test for ReverseList
	l1 = ReverseList(l1);
	PrintList(l1);
}


