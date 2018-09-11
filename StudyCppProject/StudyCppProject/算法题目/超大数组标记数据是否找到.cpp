#include<iostream>
#include "���������������Ƿ��ҵ�.h"
using namespace std;


void setNum(byte &num, int i)
{
	//����iΪ1��ʱ��8λ��������������ʾ��[hh hh ii ll] 
	//[ii]�滻����
	byte bit_2 = num >> (2 * i);//������ǰλ��[ii]���֣�������ʱ����bit_2�����2λ����
	bit_2 &= 0x03;//ֻ���������λ[ & 0011]
	//[hh hh]����ԡ���λ����
	int high_move = (2 * (1 + i));
	byte high = (num >> high_move) << high_move;//������ǰ�ĸ�λ����[hh hh xx xx]
	//[ll]����ԡ���λ����
	int low_move = (2 * (4 - i));
	byte low = (num << low_move) >> low_move;//ͨ����λȥ����λ�Լ��滻����[xx xx xx ll]

	switch (bit_2)
	{
	case 0:case 1:
	{
		++bit_2;//��00����Ϊ01�������01�͸���Ϊ10
	}
	//10����Ҫ���£�11��ʱ���ã�������
	}
	//[ii]�Ƶ�ԭ����λ�ã�������������ͨ���������ƴ�ӡ�����
	num = high | (bit_2 << (2 * i)) | low;
}

void find()
{
	//2 5000 0000
	unsigned size = 25000000;//2��5������

	
	const unsigned num_size = 1 << 30;//�ܹ�2^32��������������λ��ʾһ��������ôһ��Byte���Ա�ʾ4��������ô��ֻ��Ҫ2^30�������ɣ�Ҳ����
	const unsigned group_num = 2 << 5;
	const unsigned group_size = num_size / group_num;
	
	byte **group = new byte*[group_num];//ռ��1GB��С
	for (unsigned i = 0; i < group_num; ++i)
	{
		group[i] = new byte[group_size];
		memset(group[i], 0, group_size);
	}

	for (unsigned i = 0; i < size; ++i)//����5������
	{
		int num = rand() % 10;//��������޸�Ϊ��������ĵط�����ǰ������ֻ֤��0~9�����֣�

		unsigned index = num / 4;//����һ��char���ڼ�¼�ĸ����֣���ô�ȸ��ݵ�ǰ����������ڵ��±�
		unsigned j = num % 4;//��Ӧ��char�еĵڼ�������j�������0~3��4��λ��

		//����һ���޷�����ϴ�ռ䣬���Է�Ϊ�˶�ά����
		unsigned index_i = index / group_size;//��������ά�±�
		unsigned index_j = index % group_size;//�������һά�±�

		byte temp = group[index_i][index_j];//��ȡ
		setNum(temp, j);
		group[index_i][index_j] = temp;//д��
	}
	for (unsigned i = 0; i < group_num; ++i)
	{
		for (unsigned j = 0; j < group_size; ++j)
		{
			for (unsigned k = 0; k < 4; ++k)
			{
				char bit_2 = group[i][j] >> (2 * k);
				bit_2 &= 0x03;
				if (bit_2 == 3)//Ҳ����λ��Ϊ11��ʱ��
				{
					cout << (i*group_size + j) * 4 + k << endl;
				}
			}
		}
	}
}