#pragma once
#include<iostream>

/*������Ҫһ��������ṹ*/
struct ListNode//�ýṹ���ʾ����ڵ�
{
	ListNode* next;//��һ���ڵ�
};

/*
���ܣ���ⵥ�����Ƿ���ڻ�
����ֵ��
	true�����ڻ�
	false�������ڻ�
*/
bool isExit(ListNode* list_head);

/*
���ܣ����Թ����Ƿ����ķ���
ʾ����
	int main()
	{
		test();
	}
*/
void test();