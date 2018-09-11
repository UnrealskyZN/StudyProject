#include<iostream>
#include "�������Ƿ���ڻ�.h"
using namespace std;

bool isExit(ListNode * list_head)
{
	ListNode* slow = list_head;//��ָ�룬���߳�ʼ����Ϊ�������ͷָ��
	ListNode* fast = list_head;//��ָ��
	//nullptr�����ָ�룬Ҳ���Ǵ��������޻������������������·���false
	while (nullptr != fast)
	{
		//1.��ָ�����ƶ���һ���ƶ�����
		for (int i = 0; i < 2; ++i)
		{
			fast = fast->next;
			//����һ����һ��
			if (nullptr == fast)//1.1ʱ���ж��Ƿ�Ϊ������
				return false;
			else if (fast == slow)//1.2ʱ���ж��Ƿ���ڻ�
				return true;
		}
		//2.��ָ����ƶ���һ���ƶ�һ��
		slow = slow->next;
		//2.1����slow�ߵĿ϶���fast�������Բ��ᷢ��slow����nullptr��ʱ��
		//2.2�ж��Ƿ���ڻ�
		if (fast == slow)
			return true;
	}
	return false;
}

void test()
{
	ListNode *n1 = new ListNode();//ͷ
	ListNode *n2 = new ListNode();
	ListNode *n3 = new ListNode();
	ListNode *n4 = new ListNode();
	ListNode *n5 = new ListNode();
	n1->next = n2;//�˴����������޸ģ��γɸ�������
	n2->next = n3;
	n3->next = n2;
	n4->next = n5;
	n5->next = nullptr;

	if (isExit(n1))//ֻ����ݷ���ֵtrue����false������л�����û�л�
	{
		cout << "���ڻ�" << endl;
	}
	else
	{
		cout << "�����ڻ�" << endl;
	}
}