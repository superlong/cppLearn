/*
 * LinkedList.h
 *
 *  Created on: 2016年7月15日
 *      Author: weilongy
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* CreateList();
void PrintList(ListNode* head);




#endif /* LINKEDLIST_H_ */
