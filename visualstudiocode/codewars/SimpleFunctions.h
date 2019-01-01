#include <cctype>
#include <string>
using std::string;

//加密函数，将ascii码字符串字符加上rule后得到新字符串.
//2017-11-08 18:09:16
string encrypt(string text, int rule)
{
    if (0 == text.length()) {
        return "";
    }

    string encrypted_text(text.length(), '\0');
    for (unsigned int i = 0; i < text.length(); ++i) {
        encrypted_text[i] += (text[i] + rule) % 256;
    }

    return encrypted_text;
};

// accum("abcd");    // "A-Bb-Ccc-Dddd"
// accum("RqaEzty"); // "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
// accum("cwAt");    // "C-Ww-Aaa-Tttt"
string accum(const string& s)
{
    string expected = "";
    for (unsigned int i = 0; i < s.length(); ++i) {
        char c = (s[i] > 'Z') ? s[i] : (s[i] + 32);
        expected += (c - 32);
        for (unsigned int j = 0; j < i; ++j) {
            expected += c;
        }

        if (i != (s.length() - 1)) {
            expected += '-';
        }
    }
    return expected;
}

string accum_two(const string& s)
{
    string expected;
    for (unsigned int i = 0; i < s.length(); ++i) {
        expected.append("-");
        expected.append(string(1, toupper(s[i])));
        expected.append(string(i, tolower(s[i])));
    }
    return expected.substr(1, result.length());
}

// https://www.codewars.com/kata/basics-07-calculate-sin-x-too-easy/cpp
// 利用泰勒公式求sinx的值
// 2017-11-20 14:54:12
#define PI 3.141592653
double sin(double deg)
{
    deg = deg / 180.0 * PI;
    double result = deg;
    double snowball = deg;
    for (unsigned int i = 1, j = 2; i < 8; ++i, j += 2) {
        snowball = (-1) * snowball * deg * deg / (j * j + j);
        result += snowball;
    }

    return result;
}
