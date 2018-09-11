#pragma once
#include <iostream>
#include <string>
using namespace std;//Ϊ�˼�����д��������...ʵ����Ŀ��������

/*
������Ŀǰ��֧������

���䣺Ŀǰ��������������Ҫ�Ľ��ģ�����洢numberΪ�˺������ּ��㷽�㣬���Ƿ��Ŵ�ȽϺ�
*/
class BigNumber
{
private:
	string number;//��ʾ��ǰ��ֵ���ַ��������ǲ��������ţ�
	bool is_negative;//���ڼ�¼��ǰ��ֵ�Ƿ��Ǹ���
public:
	BigNumber(string number);
	BigNumber(const BigNumber& num);
	static BigNumber add(const BigNumber& a, const BigNumber &b);
	static BigNumber minus(const BigNumber& a, const BigNumber &b);
	static BigNumber mul(const BigNumber& a, const BigNumber &b);
	static BigNumber div(const BigNumber& a, const BigNumber &b);//��δ�Գ�������жϣ����費�ᷢ���������
	void show()
	{
		if (is_negative)
			cout << "-";
		reverse(number.begin(), number.end());
		cout << number << endl;
		reverse(number.begin(), number.end());
	}
private:
	/*

	����ֵ��
		1��a�Ƚϴ�
		2��b�Ƚϴ�
		3��ab���
	*/
	static int changeLong(const BigNumber& a, const BigNumber &b);
	
	static BigNumber minus2(const BigNumber& large, const BigNumber &small, bool is_neg);
	static BigNumber mul2(const BigNumber& large, const BigNumber &small, bool is_neg);
	
	static BigNumber mul2(const BigNumber& num, int time, int pow_10);
};

/*
���Դ��룺
	int main()
	{
		test();
		return 0;
	}
*/
void test();



