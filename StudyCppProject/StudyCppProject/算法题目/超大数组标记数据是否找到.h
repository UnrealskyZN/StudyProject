#pragma once
/*�ܾ���ǰ���ĵ���...����ܶණ���е���*/

typedef unsigned char byte;

/*
���ܣ�����find������ɸ���Ŀ
������
	num��һ��num��8λ��[00 00 00 00]����λ��ʾһ������00��ʾ�����ڣ�01��ʾ����һ�Σ�10��ʾ���ڶ�Σ�11��ʱ����
	i����num��Ϊ4�������ɵ͵���Ϊ0,1,2,3�����ڼ�¼���ݣ�i�����±�
*/
void setNum(byte &num, int i);

/*
���ܣ�
	
���Դ��룺
	int main()
	{
		find();
		system("pause");
		return 0;
	}
*/
void find();

