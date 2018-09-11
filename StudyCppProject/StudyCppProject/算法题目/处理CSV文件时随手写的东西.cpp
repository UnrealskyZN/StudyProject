#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip>
#include <fstream>
#include<vector>
#include<string>
using namespace std;

const char province_list[][40] = {
	"河北省","山西省","辽宁省","吉林省","黑龙江省","江苏省","浙江省","安徽省","福建省",
	"江西省","山东省","河南省","湖北省","湖南省","广东省","海南省","四川省","贵州省",
	"云南省","陕西省","甘肃省","青海省","台湾省",
	"西藏自治区","广西壮族自治区","内蒙古自治区","宁夏回族自治区","新疆维吾尔自治区",
	"北京市","上海市","天津市","重庆市",
	"香港特别行政区","澳门特别行政区"
};

void SplitString(const std::string & s, std::vector<std::string>& v, const std::string & c)
{
	string::size_type pos1, pos2;
	pos1 = 0;
	pos2 = s.find(c);
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));//将分隔符号前面的内容压入栈

		pos1 = pos2 + c.size();//跳过分隔符号部分
		pos2 = s.find(c, pos1);//从pos1之后开始找
	}
	if (pos1 != s.length())//如果不是以分隔符结尾的，那么也将剩余内容压入栈
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
	{//多个点的坐标系

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
//	vector<string> col_v;//临时用的
//	{//
//		in.open("Organization.csv", ios::in);
//		string str;
//		getline(in, str);//吞掉第一行
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
//		out = fopen("AimCSV.csv", "wb");//输出文件
//		{
//			getline(in, str);//吞掉第一行
//			str += ",";
//			fwrite(str.c_str(), 1, str.length(), out);//第一行
//			for (auto &s : col_name)
//			{
//				fwrite(s.c_str(), 1, s.length(), out);
//			}
//			fwrite("\r\n", 1, 2, out);
//
//			while (getline(in, str))
//			{
//				SplitString(str, col_v, ",");
//				//原始内容
//				fwrite(str.c_str(), 1, str.length(), out);//当前行
//				//填充内容
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

