// https://www.codewars.com/kata/a-rule-of-divisibility-by-7/cpp
// 2017-11-08 22:32:54
#include <utility>

class DivSeven {
public:
    static std::pair<long long, long long> seven(long long m);
};

/*
A number m of the form 10x + y is divisible by 7 if and only if x − 2y is divisible by 7.
*/
std::pair<long long, long long> DivSeven::seven(long long m)
{
    long long times = 0; //计算次数

    while (m > 99) {
        m = m / 10 - 2 * (m % 10);
        times++;
    }

    return std::make_pair(m, times);
}
