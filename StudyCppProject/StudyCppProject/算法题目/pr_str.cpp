//该文件是不能用的
#pragma warning(disable:4996)
#include<iostream>
#include<fstream>
#include<cstdarg>
#include<string>
#include <direct.h>
#define FILE_PATH	"C:\\Users\\12965\\Desktop\\台词.txt"
#define FILE_PATH2	"C:\\Users\\12965\\Desktop\\台词.prtl"

#define PATH	"C:\\Users\\UnrealSky_ZN_PC\\Desktop\\1\\"
#define H_KIND	".h"
#define C_KIND	".cpp"
using namespace std;

bool change(string &str, string &oldStr, string &newStr)
{
	int index = str.find(oldStr);
	if (index >= 0)
	{
		str.replace(index, oldStr.length(), newStr, 0, newStr.length());
		return true;
	}
	return false;
}

void defineToCase()
{
	ifstream in;
	ofstream out;
	in.open(FILE_PATH);
	out.open(FILE_PATH2);
	char line[200];
	string tabstr = "\t";
	string nullstr = "";
	while (in.getline(line, sizeof(line)))
	{
		string str = line;
		bool tag;
		do
		{
			str.shrink_to_fit();
			tag = change(str, tabstr,nullstr);
		} while (tag);//不断的寻找同一行
		out << "case " << str.c_str() << ":" << endl;
		out << "{" << endl;
		out << "CCLOG(\"This is " << str.c_str() << "\");" << endl;
		out << "break;" << endl;
		out << "};" << endl;
	}
	out.close();
	in.close();
}

//
void sceneTemplate(ifstream &in, ofstream &out, string &t, string &scenename)
{
	char line[200];
	while (in.getline(line,sizeof(line)))
	{
		string str = line;
		bool tag;
		do
		{
			str.shrink_to_fit();
			tag = change(str, t, scenename);
		} while (tag);//不断的寻找同一行
		out << str.c_str() << endl;
	}
}
void templateToHandCpp()
{
	ifstream in;
	ofstream out;
	string oldStr, newStr, oldPath, newPath;
	string kindgroup[2] = { H_KIND,C_KIND };
	string group[] = { "AchievementScene", "HeroScene", "techTreeScene", "CastleScene",
		"MonsterManualScene", "ShopScene" };
	for (int i = 0; i < sizeof(group) / sizeof(string); i++)
	{
		oldStr = "TemplateScene";
		newStr = group[i];
		for (int j = 0; j < 2; j++)
		{
			oldPath = PATH + oldStr + kindgroup[j];
			newPath = PATH + newStr + kindgroup[j];
			in.open(oldPath.c_str());
			out.open(newPath.c_str());
			sceneTemplate(in, out, oldStr, newStr);
			out.close();
			in.close();
		}

	}
}

wstring Str2Wstr(string str)
{
	if (str.length() == 0)
		return L"";

	std::wstring wstr;
	wstr.assign(str.begin(), str.end());
	return wstr;
}
std::wstring s2ws(const std::string& s)
{
	setlocale(LC_ALL, "chs");
	const char* _Source = s.c_str();
	size_t _Dsize = s.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest, _Source, _Dsize);
	std::wstring result = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, "C");
	return result;
}

void prTileChange()
{
	ifstream template_file;
	ifstream title_file;
	ofstream out_file;
	template_file.open(FILE_PATH2);
	title_file.open(FILE_PATH);

	wstring old_str = L"台词模板";
	string new_str;
	int line_index = 0;

	/*wchar_t *tempwc = new wchar_t[20000];
	int index = 0;*/
	wstring template_str;
	wchar_t wch;
	//template_file.read((char*)(&wch), 2);//读掉开头区别
	while (template_file.read((char*)(&wch),2))
	{
		if (wch == 0x000D) // 判断回车
		{
			template_str.append(1, wch);
			break;
		}
		else
		{
			template_str.append(1, wch);
		}
	}
	//template_file.getline((char*)tempwc, 40000);
	//delete[] tempwc;

	auto p = template_str.find_first_of(old_str);
	int old_len = old_str.length();



	while (title_file >> new_str)//读取每一行台词
	{
		wstring new_strw = s2ws(new_str);
		int new_len = new_strw.length();
		template_str.replace(p, old_len, new_strw, 0, new_len);
		old_len = new_len;

		char file_name[100];
		sprintf_s(file_name, "C:\\Users\\12965\\Desktop\\台词文件夹\\title_%04d.prtl", line_index++);
		out_file.open(file_name);
		//out_file << 0xFFFE;
		out_file.write("\xff\xfe", 2);
		out_file.write((char*)template_str.c_str(), template_str.length() * 2);
		//out_file << template_str.c_str() << endl;
		out_file.close();
	}


}

void showStr(char* str, ...)
{
	va_list args;//定义可变参数指针
	va_start(args, str);//str为最后一个固定参数(既接下来的就是...的内容）
	char* temp = str;//va_arg返回的是可选参数, 不包括固定参数，所以一开始要先获得固定参数
	while (temp != nullptr)
	{
		cout << temp << endl;
		temp = va_arg(args, char*);//告知按照什么类型数据取出
	}
	va_end(args);//清空参数指针
}

int main()
{
	//templateToHandCpp();
	prTileChange();
	return 0;
}
