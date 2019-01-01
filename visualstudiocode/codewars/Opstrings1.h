#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Opstrings1 {
public:
public:
    static string rot(const string& strng);
    static string selfieAndRot(const string& strng);
    template <typename Func>
    static string oper(Func func, const string& s);

private:
    static vector<string> split(const string& str);
    static string join(vector<string>& lines);
};

/*
abcd\nefgh\nijkl\nmnop  =>  [abcd,efgh,ijkl,mnop]
*/
vector<string> Opstrings1::split(const string& str)
{
    vector<string> result;
    istringstream ss(str);
    string line;
    while (getline(ss, line, '\n')) {
        result.push_back(line);
    }

    return result;
}

/*
[abcd,efgh,ijkl,mnop]   =>  abcd\nefgh\nijkl\nmnop
*/
string Opstrings1::join(vector<string>& lines)
{
    string result = "";
    unsigned int i = 0;
    for (; i < lines.size() - 1; ++i) {
        result += lines[i] + '\n';
    }
    result += lines[i];

    return result;
}

// rotation
// abcd --> ponm
// efgh     lkji
// ijkl     hgfe
// mnop     dcba
string Opstrings1::rot(const string& str)
{
    vector<string> lines = split(str);

    string result = "";
    for (int i = lines.size() - 1; i >= 0; --i) {
        for (int j = lines.size() - 1; j >= 0; --j) {
            result += lines[i][j];
        }
        if (i != 0) {
            result += "\n";
        }
    }

    return result;
}

// selfie_and_rot
// abcd --> abcd....
// efgh     efgh....
// ijkl     ijkl....
// mnop     mnop....
//          ....ponm
//          ....lkji
//          ....hgfe
//          ....dcba
string Opstrings1::selfieAndRot(const string& str)
{
    vector<string> lines = split(str);
    string result = "";
    for (unsigned int i = 0; i < lines.size(); ++i) {
        result += lines[i] + string(lines.size(), '.') + "\n";
    }

    string reverse;
    for (int i = lines.size() - 1; i >= 0; --i) {
        reverse = "";
        for (int j = lines.size() - 1; j >= 0; --j) {
            reverse += lines[i][j];
        }
        if (i != 0)
            result += string(lines.size(), '.') + reverse + "\n";
        else
            result += string(lines.size(), '.') + reverse;
    }

    return result;
}

template <typename Func>
string Opstrings1::oper(Func func, const string& s)
{
    return func(s);
}

// int main()
// {
// 	string s = "fijuoo\nCqYVct\nDrPmMJ\nerfpBA\nkWjFUG\nCVUfyL";
// 	cout << Opstrings1::rot(s) << endl
// 		<< endl;
// 	cout << Opstrings1::selfieAndRot(s) << endl
// 		<< endl;
// 	return 0;
// }
