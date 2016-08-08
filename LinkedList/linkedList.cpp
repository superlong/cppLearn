/*
 * linkedList.cpp
 *
 *  Created on: 2016年7月15日
 *      Author: weilongy
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;

ListNode* CreateList()
{
	ListNode dummy(0);
	ListNode* head = &dummy;
	cout<<"Please input numbers (999 to exit):"<<endl;
	int idata;
	while (1) {
		cin>>idata;
		if (idata == 999) break;
		head->next = new ListNode(idata);
		head = head->next;
	}
	return dummy.next;
}

void PrintList(ListNode* head)
{
	while (head) {
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}

