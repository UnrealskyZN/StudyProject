#include<iostream>
#include "单链表是否存在环.h"
using namespace std;

bool isExit(ListNode * list_head)
{
	ListNode* slow = list_head;//慢指针，两者初始化均为单链表的头指针
	ListNode* fast = list_head;//快指针
	//nullptr代表空指针，也就是代表单链表无环的情况，在这类情况下返回false
	while (nullptr != fast)
	{
		//1.快指针先移动，一次移动两步
		for (int i = 0; i < 2; ++i)
		{
			fast = fast->next;
			//↓走一步测一次
			if (nullptr == fast)//1.1时刻判断是否为单链表
				return false;
			else if (fast == slow)//1.2时刻判断是否存在环
				return true;
		}
		//2.慢指针后移动，一次移动一步
		slow = slow->next;
		//2.1由于slow走的肯定比fast慢，所以不会发生slow到达nullptr的时候
		//2.2判断是否存在环
		if (fast == slow)
			return true;
	}
	return false;
}

void test()
{
	ListNode *n1 = new ListNode();//头
	ListNode *n2 = new ListNode();
	ListNode *n3 = new ListNode();
	ListNode *n4 = new ListNode();
	ListNode *n5 = new ListNode();
	n1->next = n2;//此处可以任意修改，形成各种链表
	n2->next = n3;
	n3->next = n2;
	n4->next = n5;
	n5->next = nullptr;

	if (isExit(n1))//只需根据返回值true或者false来输出有环或者没有环
	{
		cout << "存在环" << endl;
	}
	else
	{
		cout << "不存在环" << endl;
	}
}