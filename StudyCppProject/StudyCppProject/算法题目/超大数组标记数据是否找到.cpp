#include<iostream>
#include "超大数组标记数据是否找到.h"
using namespace std;


void setNum(byte &num, int i)
{
	//假设i为1的时候，8位代表内容如右所示：[hh hh ii ll] 
	//[ii]替换部分
	byte bit_2 = num >> (2 * i);//保留当前位置[ii]部分，但是暂时放在bit_2的最低2位保存
	bit_2 &= 0x03;//只保留最低两位[ & 0011]
	//[hh hh]“相对”高位部分
	int high_move = (2 * (1 + i));
	byte high = (num >> high_move) << high_move;//保留当前的高位部分[hh hh xx xx]
	//[ll]“相对”地位部分
	int low_move = (2 * (4 - i));
	byte low = (num << low_move) >> low_move;//通过移位去除高位以及替换部分[xx xx xx ll]

	switch (bit_2)
	{
	case 0:case 1:
	{
		++bit_2;//将00更新为01，如果是01就更新为10
	}
	//10不需要更新，11暂时不用，不存在
	}
	//[ii]移到原来的位置，其他两部份再通过或操作“拼接”即可
	num = high | (bit_2 << (2 * i)) | low;
}

void find()
{
	//2 5000 0000
	unsigned size = 25000000;//2亿5个数字

	
	const unsigned num_size = 1 << 30;//总共2^32个整形数，以两位表示一个数，那么一个Byte可以表示4个数，那么就只需要2^30个数即可，也就是
	const unsigned group_num = 2 << 5;
	const unsigned group_size = num_size / group_num;
	
	byte **group = new byte*[group_num];//占用1GB大小
	for (unsigned i = 0; i < group_num; ++i)
	{
		group[i] = new byte[group_size];
		memset(group[i], 0, group_size);
	}

	for (unsigned i = 0; i < size; ++i)//两亿5个数字
	{
		int num = rand() % 10;//这里可以修改为数据输入的地方（当前这样保证只有0~9的数字）

		unsigned index = num / 4;//由于一个char用于记录四个数字，那么先根据当前数字求出所在的下标
		unsigned j = num % 4;//对应于char中的第几个，用j来标记了0~3这4个位置

		//由于一次无法申请较大空间，所以分为了二维数组
		unsigned index_i = index / group_size;//获得数组二维下标
		unsigned index_j = index % group_size;//获得数组一维下标

		byte temp = group[index_i][index_j];//读取
		setNum(temp, j);
		group[index_i][index_j] = temp;//写回
	}
	for (unsigned i = 0; i < group_num; ++i)
	{
		for (unsigned j = 0; j < group_size; ++j)
		{
			for (unsigned k = 0; k < 4; ++k)
			{
				char bit_2 = group[i][j] >> (2 * k);
				bit_2 &= 0x03;
				if (bit_2 == 3)//也就是位置为11的时候
				{
					cout << (i*group_size + j) * 4 + k << endl;
				}
			}
		}
	}
}