#include <iostream>
#include <typeinfo> //typeid
#include <windows.h> //byte
using namespace std;

double method(byte x, double y)
{
    //cout << (typeof((short)x / y * 2) == typeof(short)) << endl;
    cout << typeid((short)x / y * 2).name() << endl;
    cout << typeid((short)(x / y * 2)).name() << endl;

    double a = 1;
    short b = 0;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    return (short)x / y * 2;
}

int main()
{
    method('d', 123.00);
    return 0;
}
