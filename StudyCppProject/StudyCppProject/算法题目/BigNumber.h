#pragma once
#include <iostream>
#include <string>
using namespace std;//为了简便就先写在这里了...实际项目绝不允许

/*
描述：目前仅支持整数

补充：目前大量东西都是需要改进的，比如存储number为了后续各种计算方便，还是反着存比较好
*/
class BigNumber
{
private:
	string number;//表示当前数值的字符串（但是不包含符号）
	bool is_negative;//用于记录当前数值是否是负数
public:
	BigNumber(string number);
	BigNumber(const BigNumber& num);
	static BigNumber add(const BigNumber& a, const BigNumber &b);
	static BigNumber minus(const BigNumber& a, const BigNumber &b);
	static BigNumber mul(const BigNumber& a, const BigNumber &b);
	static BigNumber div(const BigNumber& a, const BigNumber &b);//并未对除零进行判断，假设不会发生这种情况
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

	返回值：
		1：a比较大
		2：b比较大
		3：ab相等
	*/
	static int changeLong(const BigNumber& a, const BigNumber &b);
	
	static BigNumber minus2(const BigNumber& large, const BigNumber &small, bool is_neg);
	static BigNumber mul2(const BigNumber& large, const BigNumber &small, bool is_neg);
	
	static BigNumber mul2(const BigNumber& num, int time, int pow_10);
};

/*
测试代码：
	int main()
	{
		test();
		return 0;
	}
*/
void test();



