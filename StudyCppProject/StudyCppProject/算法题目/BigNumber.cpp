#include"BigNumber.h"

BigNumber::BigNumber(string number)
{
	unsigned sub_index = 0;
	if (number[0] == '-')
	{
		is_negative = true;
		++sub_index;
	}
	else
	{
		is_negative = false;
	}
	for (unsigned i = sub_index; i < number.length(); ++i)
	{
		if (number[i] == '0')
			++sub_index;
		else
			break;
	}
	this->number = number.substr(sub_index);
	reverse(this->number.begin(), this->number.end());
}

BigNumber::BigNumber(const BigNumber & num)
{
	number = num.number;
	is_negative = num.is_negative;
}

BigNumber BigNumber::add(const BigNumber & a, const BigNumber & b)
{
	if (a.is_negative != b.is_negative)
	{
		BigNumber c = b;
		c.is_negative = !c.is_negative;//���ķ���
		return minus(a, c);
	}
	int a_one = 0, b_one = 0;//����ӷ���ĳһλ
	int up_one = 0;//�����λ
	string temp_num = "";
	//ѡ�����߳��Ƚ϶̵�һ��
	int a_l = a.number.length();
	int b_l = b.number.length();
	int len = a_l < b_l ? a_l : b_l;

	for (int i = 0; i < len; ++i)
	{
		a_one = a.number[i] - '0';
		b_one = b.number[i] - '0';
		up_one = a_one + b_one + up_one;
		temp_num += up_one % 10 + '0';
		up_one = up_one / 10;
	}
	if (a_l > b_l)//�ӷ�a+b��a�Ƚϳ���ʱ����Ҫ��¼a�Ĳ���
	{
		for (int i = len; i < a_l; ++i)
		{
			a_one = a.number[i] - '0';
			up_one = up_one + a_one;
			temp_num += up_one % 10 + '0';
			up_one = up_one / 10;
		}
	}
	else if (a_l < b_l)//�ӷ�a+b��b�Ƚϳ���ʱ����Ҫ��¼b�Ĳ���
	{
		for (int i = len; i < b_l; ++i)
		{
			b_one = b.number[i] - '0';
			up_one = up_one + b_one;
			temp_num += up_one % 10 + '0';
			up_one = up_one / 10;
		}
	}
	if (up_one != 0)
	{//��λ
		temp_num += up_one + '0';
		up_one = up_one / 10;
	}
	reverse(temp_num.begin(), temp_num.end());
	BigNumber r(temp_num);
	r.is_negative = a.is_negative;
	return r;
}

BigNumber BigNumber::minus(const BigNumber & a, const BigNumber & b)
{
	if (a.is_negative != b.is_negative)
	{
		BigNumber c = b;
		c.is_negative = !c.is_negative;//���ķ���
		return add(a, c);
	}
	switch (changeLong(a, b))
	{
	case 1:return minus2(a, b, a.is_negative);//a-b��ʱ��|a|�Ƚϴ���ǰ���a�ķ���
	case 2:return minus2(b, a, !b.is_negative);//a-b��ʱ��|b|�Ƚϴ���ǰ���-b�ķ��ţ�����Ҫ��!����ȡ����
	case 3://��ͬ�Ļ���ȻΪ0
	{
		BigNumber r("0");
		r.is_negative = false;
		return r;
	}
	}
}

BigNumber BigNumber::mul(const BigNumber & a, const BigNumber & b)
{
	bool is_neg;
	if (a.is_negative != b.is_negative)
		is_neg = true;
	else
		is_neg = false;
	switch (changeLong(a, b))
	{
	case 1:return mul2(a, b, is_neg);
	case 2:case 3:return mul2(b, a, is_neg);//������ͬ��ʱ��������˳�򶼿���
	}
}

BigNumber BigNumber::div(const BigNumber & a, const BigNumber & b)
{
	bool is_neg;
	if (a.is_negative != b.is_negative)
		is_neg = true;
	else
		is_neg = false;
	BigNumber one("1");
	BigNumber r("0");
	BigNumber temp_a = a;
	temp_a.is_negative = b.is_negative;//תΪͬ��
	while (changeLong(temp_a, b) != 2 && temp_a.is_negative == b.is_negative)//a�Ƚϴ������һ���������¶�ִ��ѭ��
	{
		temp_a = minus(temp_a, b);
		r = add(r, one);
	}
	r.is_negative = is_neg;
	return r;
}

int BigNumber::changeLong(const BigNumber & a, const BigNumber & b)
{
	int a_l = a.number.length();
	int b_l = b.number.length();
	int status;//1��2��3��ʾa�Ƚϴ�b�Ƚϴ�һ����
	if (a_l > b_l)
	{//aֵ�Ƚϴ�
		status = 1;
	}
	else if (b_l > a_l)
	{//bֵ�Ƚϴ�
		status = 2;
	}
	else
	{//������ͬʱ
		status = 0;
		for (int i = a_l - 1; i >= 0; --i)
		{
			if (a.number[i] > b.number[i])
			{
				status = 1;
				break;
			}
			else if (a.number[i] < b.number[i])
			{
				status = 2;
				break;
			}
		}
		if (status == 0)//����forѭ��break�����Ժ��ֱ���Ϊ3
			status = 3;
	}
	return status;
}

BigNumber BigNumber::minus2(const BigNumber & large, const BigNumber & small, bool is_neg)

{
	int a_one = 0, b_one = 0;//���������ĳһλ
	int delta = 0;
	int down_num = 0;
	string temp_num = "";
	//ѡ�����߳��Ƚ϶̵�һ��
	int a_l = large.number.length();
	int b_l = small.number.length();
	for (int i = 0; i < b_l; ++i)
	{
		a_one = large.number[i] - '0';
		b_one = small.number[i] - '0';
		delta = a_one - delta - b_one;
		down_num = 0;
		if (delta < 0)
		{
			down_num = 1;
			delta += 10;//
		}
		temp_num += delta + '0';
		if (down_num == 1)
		{
			delta = 1;
		}
		else
		{
			delta = 0;
		}
	}
	for (int i = b_l; i < a_l; ++i)
	{
		a_one = large.number[i] - '0';
		delta = a_one - delta;
		down_num = 0;
		if (delta < 0)
		{
			down_num = 1;
			delta += 10;
		}
		temp_num += delta + '0';
		if (down_num == 1)
		{
			delta = 1;
		}
		else
		{
			delta = 0;
		}
	}
	reverse(temp_num.begin(), temp_num.end());
	BigNumber r(temp_num);
	r.is_negative = is_neg;
	return r;
}

BigNumber BigNumber::mul2(const BigNumber & large, const BigNumber & small, bool is_neg)
{
	int a_l = large.number.length();
	int b_l = small.number.length();
	int time;
	BigNumber r("0");//��ʼֵΪ0
	r.is_negative = false;
	for (int i = 0; i < b_l; ++i)
	{
		time = small.number[i] - '0';
		if (time == 0)//��0������
			continue;
		r = BigNumber::add(r, mul2(large, time, i));
	}
	r.is_negative = is_neg;
	return r;
}

BigNumber BigNumber::mul2(const BigNumber & num, int time, int pow_10)
{
	string temp_num = "";
	int up_num = 0;//��λ��
	int num_one;
	for (int i = 0; i < num.number.length(); ++i)
	{
		num_one = num.number[i] - '0';
		up_num = num_one * time + up_num;
		temp_num += up_num % 10 + '0';
		up_num = up_num / 10;
	}
	if (up_num != 0)
	{
		temp_num += up_num + '0';//���һ�ν�λ�Ͳ���Ҫ%10��
	}
	reverse(temp_num.begin(), temp_num.end());
	for (int i = 0; i < pow_10; ++i)//���0�����ڳ˷�����10��ƫ�ƣ���Ҫ���0��
	{
		temp_num += '0';
	}
	BigNumber r(temp_num);
	r.is_negative = false;//��֤����ͳһ
	return r;
}

void test()
{
	BigNumber a("-100");
	BigNumber b("-2");
	BigNumber c("23");
	BigNumber d("255");
	BigNumber::add(a, b).show();//-100+-2 = -102
	BigNumber::minus(a, c).show();//-100 - 23 = -123
	BigNumber::minus(a, b).show();//-100 - -2 = -98
	BigNumber::mul(a, b).show();//-100 * -2 = 200
	BigNumber::div(a, b).show();//-100 / -2 = 50
	BigNumber::minus(c, d).show();// 23 - 255 = -232
}