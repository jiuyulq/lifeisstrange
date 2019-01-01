// https://www.codewars.com/kata/rgb-to-hex-conversion/cpp
// 2017-11-05 13:26:53
#include <iomanip>
#include <iostream>
#include <sstream>

class RGBToHex {
public:
    static std::string rgb(int r, int g, int b);
};

std::string RGBToHex::rgb(int r, int g, int b)
{
    for (auto i : { &r, &g, &b }) {
        if (*i < 0)
            *i = 0;
        else if (*i > 255)
            *i = 255;
    }

    std::stringstream sstream;
    sstream.fill('0');
    sstream << std::hex << std::uppercase
            << std::setw(2) << r
            << std::setw(2) << g
            << std::setw(2) << b;

    return sstream.str();
}

/*
#include "codewars/RGBToHex.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << RGBToHex::rgb(255, 255, 255) << endl;
    cout << RGBToHex::rgb(148, 0, 211) << endl;
    return 0;
}
*/
