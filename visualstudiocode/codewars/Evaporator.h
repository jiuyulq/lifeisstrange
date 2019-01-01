// http://www.codewars.com/kata/deodorant-evaporator/cpp
// 2017-11-04 23:02:59
#include<cmath>
using namespace std;

class Evaporator {

public:
    static int evaporator(double content, double evap_per_day, double threshold);
};

// by jiuyulq
int Evaporator::evaporator(double content, double evap_per_day, double threshold)
{
    int n_day = 0;
    double remain_percent = 1 - evap_per_day / 100;
    double remain = 1;
    double threshold_percent = threshold / 100;
    while (remain > threshold_percent) {
        n_day++;
        remain *= remain_percent;
    }
    return n_day;
}

// from code wars

// ##        ######
// ##       ##    ##      threshold / 100.0
// ##       ##
// ##       ##   ####
// ##       ##    ##
// ##       ##    ##   1.0 - evap_per_day / 100.0
// ########  ######
int Evaporator::evaporator(double content, double evap_per_day, double threshold)
{
    return static_cast<int>(ceil(log(threshold / 100.0) / log(1.0 - evap_per_day / 100.0)));
}
