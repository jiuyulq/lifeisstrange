#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "cold winter."; //拷贝初始化
    string s2("cold winter"); //直接初始化

    {
        //cctype头文件中的函数
        /* page82
        isalnum;
        isalpha;
        iscntrl;
        isdigit;
        isgraph;
        islower;
        isprint;
        ispunct;
        isspace;
        isupper;
        isxdigit;
        tolower;
        toupper;
        */
        string s = "snow.";
        for (auto c : s) {
            cout << c << " " << isalpha(c) << endl;
        }
    }

    //使用迭代器完成二分搜索
    {
        string text = "abcdefg"; //必须有序
        char sought = 'a';
        auto begin = text.begin(), end = text.end();
        auto mid = begin + (end - begin) / 2;

        while (mid != begin && *mid != sought) {
            if (*mid > sought) {
                end = mid;
            } else {
                begin = mid;
            }
            mid = begin + (end - begin) / 2;
        }

        if (*mid == sought) {
            cout << "found." << endl;
        } else {
            cout << "not found." << endl;
        }
    }
}
