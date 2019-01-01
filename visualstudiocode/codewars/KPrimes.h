#include <cmath> //sqrt
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class KPrimes {
public:
    //returns an array of the k-primes between start (inclusive) and end (inclusive).
    static vector<long long> countKprimes(int k, long long start, long long end);

    // Given positive integers s and a, b, c where a is 1-prime, b 3-prime, c 7-prime find the number of solutions of a + b + c = s.
    static int puzzle(int s);

    // check to see whether num  a prime.
    static bool IsPrime(long long num);

    //count the number of prime factor.
    static int CountPrimeFactor(long long num);
};

vector<long long> KPrimes::countKprimes(int k, long long start, long long end)
{
    vector<long long> kprimes;
    for (; start <= end; ++start) {
        if (k == CountPrimeFactor(start)) {
            kprimes.push_back(start);
            //cout << start << "  ";
        }
    }
    return kprimes;
}

int KPrimes::puzzle(int s)
{
    vector<long long> primes_1 = countKprimes(1, 2, s);
    vector<long long> primes_3 = countKprimes(3, 2, s);
    vector<long long> primes_7 = countKprimes(7, 2, s);

    int result_count = 0;
    int sum_of_3;
    for (auto p1_begin = primes_1.begin(); p1_begin != primes_1.end(); ++p1_begin) {
        for (auto p3_begin = primes_3.begin(); p3_begin != primes_3.end(); ++p3_begin) {
            for (auto p7_begin = primes_7.begin(); p7_begin != primes_7.end(); ++p7_begin) {
                sum_of_3 = *p1_begin + *p3_begin + *p7_begin;
                if (s == sum_of_3) {
                    ++result_count;
					//cout << *p1_begin << " " << *p3_begin << " " << *p7_begin << endl;
					break;
                } else if (s < sum_of_3) {	//sum out of range.
					if( p7_begin == primes_7.begin() ){
						p3_begin = primes_3.end()-1;
						if( p3_begin == primes_3.begin()){
							p1_begin = primes_1.end()-1;
						}
					}
                    break;
                }
            }
        }
    }

    return result_count;
}

bool KPrimes::IsPrime(long long num)
{
    if (num <= 3) {
        return num >= 2;
    } else if (0 == num % 2 || 0 == num % 3) {
        return false;
    }

    long long sqrt_num = sqrt(num);
	for (int i = 5; i <= sqrt_num; i += 6) {
        if (0 == num % i || 0 == num % (i + 2)) {
            return false;
        }
    }

    return true;
}

int KPrimes::CountPrimeFactor(long long num)
{
    if (IsPrime(num)) {
        return 1;
    }

    int factor_count = 0;

    for (int i = 2; i * i <= num; ++i) {
        while (0 == num % i) {
            ++factor_count;
            num /= i;
            //cout << i << "*";
        }
    }

    if (num != 1) {
        ++factor_count;
        //cout << num;
    }
    //cout << endl;

    return factor_count;
}

/*
#include<iostream>
#include "codewars/KPrimes.h"

using namespace std;

int main(){
	//cout << KPrimes::CountPrimeFactor(7) <<endl;
	// cout << KPrimes::CountPrimeFactor(100) <<endl;
	// cout << KPrimes::CountPrimeFactor(1000) <<endl;
	// cout << KPrimes::CountPrimeFactor(5678) <<endl;

	KPrimes::countKprimes(5, 500, 600);

	cout << KPrimes::puzzle(138) << endl;
	cout << KPrimes::puzzle(143) << endl;
	cout << KPrimes::puzzle(250) << endl;
}
*/
