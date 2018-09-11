#pragma once
/*很久以前的文档了...具体很多东西有点乱*/

typedef unsigned char byte;

/*
功能：辅助find方法完成该题目
参数：
	num：一个num是8位，[00 00 00 00]以两位表示一个数，00表示不存在，01表示存在一次，10表示存在多次，11暂时不用
	i：将num看为4个部分由低到高为0,1,2,3，用于记录数据，i则是下标
*/
void setNum(byte &num, int i);

/*
功能：
	
测试代码：
	int main()
	{
		find();
		system("pause");
		return 0;
	}
*/
void find();

