// https://www.codewars.com/kata/56dbf59b0a10feb08c000227
// 2017-11-02 12:59:28
#include <string>

class Opstrings4 {
public:
    static std::string diag2Sym(const std::string& strng);
    static std::string rot90Counter(const std::string& strng);
    static std::string selfieDiag2Counterclock(const std::string& strng);
    // your function oper...
    static std::string oper(std::string Func(const std::string&), const std::string& s);
};

std::string Opstrings4::diag2Sym(const std::string& strng)
{
    std::string result_strng(strng.length(), '\n');
    int n = strng.find_first_of('\n');

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result_strng[j + i * (n + 1)] = strng[(n - 1 - i) + (n - 1 - j) * (n + 1)];
        }
    }

    return result_strng;
}

std::string Opstrings4::rot90Counter(const std::string& strng)
{
    std::string result_strng(strng.length(), '\n');
    int n = strng.find_first_of('\n');

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result_strng[j + i * (n + 1)] = strng[(n - 1 - i) + j * (n + 1)];
        }
    }

    return result_strng;
}

std::string Opstrings4::selfieDiag2Counterclock(const std::string& strng)
{
    std::string result_strng(strng.length() * 3 + 2, '\n');
    int n = strng.find_first_of('\n');

    int line_len = 3 * (n + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < line_len - 1; ++j) {
            if (n == j || (2 * n + 1) == j) {
                result_strng[j + i * line_len] = '|';
            } else if (j < n) {
                result_strng[j + i * line_len] = strng[j + i * ( n + 1)];
            } else if (j < (2 * n + 1)) {
				result_strng[j + i * line_len] = strng[(n - 1 - i) + (n - 1 - (j - n - 1)) * (n + 1)];
            } else {
				result_strng[j + i * line_len] = strng[(n - 1 - i) + (j - 2 * ( n + 1) ) * (n + 1)];
	        }
        }
    }

    return result_strng;
}

// your function oper...
std::string Opstrings4::oper(std::string Func(const std::string&), const std::string& s){
	return Func(s);
}

/*
// test file
#include <iostream>
#include "codewars/Opstrings4.h"
using namespace std;

int main()
{
    const string s = "abcd\nefgh\nijkl\nmnop";
	cout << "=="<<endl;
    cout << Opstrings4::oper(Opstrings4::diag2Sym, s) << endl;
	cout << "=="<<endl;
    cout << Opstrings4::oper(Opstrings4::rot90Counter, s) << endl;
	cout << "=="<<endl;
    cout << Opstrings4::oper(Opstrings4::selfieDiag2Counterclock, s) << endl;

    return 0;
}


// selfie_diag2_counterclock
// abcd|plhd|dhlp
// efgh|okgc|cgko
// ijkl|njfb|bfjn
// mnop|miea|aeim

*/
