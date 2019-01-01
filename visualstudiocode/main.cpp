#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    string codestring = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?  "; //末尾两个空格，最后一位暂不可知
    map<char, int> codemap;
    for (int i = 0; i < codestring.length(); ++i) {
        codemap.insert(std::make_pair(codestring[i], i + 1));
    }

    for (auto& val : codemap) {
        cout << val.first << " " << val.second << endl;
    }
    return 0;
}
