// https://www.codewars.com/kata/moves-in-squared-strings-iii/train/cpp
// 2017-10-31 16:20:21  create.
// 2017-11-04 18:45:26  refactor some methods.
#pragma once
#include <sstream>
#include <string>
#include <vector>

class Opstrings3 {
public:
    static std::string diag1Sym(const std::string& str);
    static std::string rot90Clock(const std::string& str);
    static std::string selfieAndDiag1(const std::string& str);
    template <typename Func>
    static std::string oper(Func func, const std::string& str);

private:
    static std::vector<std::string> split(const std::string& str);
    static std::string join(std::vector<std::string>& lines);
};

/*
    abcd\nefgh\nijkl\nmnop  =>  [abcd,efgh,ijkl,mnop]
*/
std::vector<std::string> Opstrings3::split(const std::string& str)
{
    std::vector<std::string> result;
    std::istringstream ss(str);
    std::string line;
    while (std::getline(ss, line, '\n')) {
        result.push_back(line);
    }

    return result;
}

/*
    [abcd,efgh,ijkl,mnop]   =>  abcd\nefgh\nijkl\nmnop
*/
std::string Opstrings3::join(std::vector<std::string>& lines)
{
    std::string result = "";
    unsigned int i = 0;
    for (; i < lines.size() - 1; ++i) {
        result += lines[i] + '\n';
    }
    result += lines[i];

    return result;
}

/*
abcd            aeim
efgh    ==>     bfjn
ijkl            cgko
mnop            dhlp
*/
std::string Opstrings3::diag1Sym(const std::string& str)
{
    std::vector<std::string> lines = split(str);
    std::vector<std::string> new_lines(lines.size());

    for (unsigned int i = 0; i < lines.size(); ++i) {
        new_lines[i] = "";
        for (unsigned int j = 0; j < lines.size(); ++j) {
            new_lines[i] += lines[j][i];
        }
    }

    return join(new_lines);
}

/*
abcd           miea
efgh    ==>    njfb
ijkl           okgc
mnop           plhd
*/
std::string Opstrings3::rot90Clock(const std::string& str)
{
    std::vector<std::string> lines = split(str);
    unsigned int n = lines.size();
    std::vector<std::string> new_lines(n);

    for (unsigned int i = 0; i < n; ++i) {
        new_lines[i] = "";
        for (unsigned int j = 0; j < n; ++j) {
            new_lines[i] += lines[n - 1 - j][i];
        }
    }

    return join(new_lines);
}

/*
abcd           abcd|aeim
efgh    ==>    efgh|bfjn
ijkl           ijkl|cgko
mnop           mnop|dhlp
*/
std::string Opstrings3::selfieAndDiag1(const std::string& str)
{
    std::vector<std::string> lines_left = split(str);
    std::vector<std::string> lines_right = split(diag1Sym(str));
    std::string result = "";

    unsigned int i = 0;
    for (; i < lines_left.size() - 1; ++i) {
        result += lines_left[i] + "|" + lines_right[i] + "\n";
    }
    result += lines_left[i] + "|" + lines_right[i];

    return result;
}

template <typename Func>
std::string Opstrings3::oper(Func func, const std::string& s)
{
    return func(s);
}

/*
// test file

#include "codewars/Opstrings3.h"
#include <iostream>
using namespace std;

int main()
{
    const string s = "abcd\nefgh\nijkl\nmnop";
    //Opstrings3::diag1Sym(s);
    //Opstrings3::rot90Clock(s);
    //cout << Opstrings3::selfieAndDiag1(s) << endl;

    //s = "abcd\nefgh\nijkl\nmnop"

    //=> "aeim\nbfjn\ncgko\ndhlp"
    cout << Opstrings3::oper(Opstrings3::diag1Sym, s) << endl;

    //=> "miea\nnjfb\nokgc\nplhd"
    cout << Opstrings3::oper(Opstrings3::rot90Clock, s) << endl;

    //=> "abcd|aeim\nefgh|bfjn\nijkl|cgko\nmnop|dhlp"
    cout << Opstrings3::oper(Opstrings3::selfieAndDiag1, s) << endl;

    return 0;
}
*/
