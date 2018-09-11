#pragma once
#include<iostream>

/*本题需要一个链表结点结构*/
struct ListNode//用结构体表示链表节点
{
	ListNode* next;//下一个节点
};

/*
功能：检测单链表是否存在环
返回值：
	true：存在环
	false：不存在环
*/
bool isExit(ListNode* list_head);

/*
功能：测试功能是否合理的方法
示例：
	int main()
	{
		test();
	}
*/
void test();