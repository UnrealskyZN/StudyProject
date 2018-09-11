#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip>
#include <fstream>
#include<vector>
#include<string>
using namespace std;

const char province_list[][40] = {
	"�ӱ�ʡ","ɽ��ʡ","����ʡ","����ʡ","������ʡ","����ʡ","�㽭ʡ","����ʡ","����ʡ",
	"����ʡ","ɽ��ʡ","����ʡ","����ʡ","����ʡ","�㶫ʡ","����ʡ","�Ĵ�ʡ","����ʡ",
	"����ʡ","����ʡ","����ʡ","�ຣʡ","̨��ʡ",
	"����������","����׳��������","���ɹ�������","���Ļ���������","�½�ά���������",
	"������","�Ϻ���","�����","������",
	"����ر�������","�����ر�������"
};

void SplitString(const std::string & s, std::vector<std::string>& v, const std::string & c)
{
	string::size_type pos1, pos2;
	pos1 = 0;
	pos2 = s.find(c);
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));//���ָ�����ǰ�������ѹ��ջ

		pos1 = pos2 + c.size();//�����ָ����Ų���
		pos2 = s.find(c, pos1);//��pos1֮��ʼ��
	}
	if (pos1 != s.length())//��������Էָ�����β�ģ���ôҲ��ʣ������ѹ��ջ
		v.push_back(s.substr(pos1));
}

string findData(vector<pair<string, string>> &data, string &id)
{
	for (auto &p : data)
	{
		if (p.first == id)
		{
			return p.second;
		}
	}
	return "";
}

bool isFind(const vector<string> &vec, const string& str)
{
	for (auto &s : vec)
	{
		if (s == str)
			return  true;
	}
	return false;
}

int getIndex(const vector<string> &vec, const string& str)
{
	int i = 0;
	for (auto &s : vec)
	{
		if (s == str)
			return  i;
		++i;
	}
}


bool isInside(const vector<pair<float, float>> &pos_vec, const pair<float, float> &pos)
{
	if (pos_vec.size() == 2)
	{
		if (pos.first < pos_vec[0].first)
			return false;
	}
	else
	{//����������ϵ

	}
}






int main()
{
	while (true)
	{
		PRD();
	}
	system("pause");
	return 0;
}


//int main()
//{
//	ifstream in;
//	FILE *out;
//	vector<string> col_name;
//	vector<string> col_v;//��ʱ�õ�
//	{//
//		in.open("Organization.csv", ios::in);
//		string str;
//		getline(in, str);//�̵���һ��
//		while (getline(in, str))
//		{
//			SplitString(str, col_v,",");
//			if (!isFind(col_name, col_v[3] + ","))
//			{
//				col_name.push_back(col_v[3] + ",");
//			}
//			col_v.clear();
//		}
//		in.close();
//	}
//	{
//		in.open("Organization.csv", ios::in);
//		string str;
//		out = fopen("AimCSV.csv", "wb");//����ļ�
//		{
//			getline(in, str);//�̵���һ��
//			str += ",";
//			fwrite(str.c_str(), 1, str.length(), out);//��һ��
//			for (auto &s : col_name)
//			{
//				fwrite(s.c_str(), 1, s.length(), out);
//			}
//			fwrite("\r\n", 1, 2, out);
//
//			while (getline(in, str))
//			{
//				SplitString(str, col_v, ",");
//				//ԭʼ����
//				fwrite(str.c_str(), 1, str.length(), out);//��ǰ��
//				//�������
//				str = "";
//				int index = getIndex(col_name, col_v[3]);
//				for (int i = 0; i < index; ++i)
//				{
//					str += ",";
//				}
//				str += "1,";
//				for (int i = index; i < col_v.size(); ++i)
//				{
//					str += ",";
//				}
//				str += "\r\n";
//				fwrite(str.c_str(), 1, str.length(), out);
//				col_v.clear();
//			}
//		}
//		in.close();
//		fclose(out);
//	}
//
//	//system("pause");
//	return 0;
//}

