#include <iostream>
using namespace std;

int main()
{
    //初始化空指针
    {
        int* p1 = nullptr; //from c++ 11
        int* p2 = 0;
        int* p3 = NULL; //尽量别使用

        cout << p1 << " " << p2 << endl;
        cout << p3 << endl;

        if (p1)
            cout << "not a null pointer." << endl;
        else
            cout << "null pointer." << endl;
    }

    //void *

    {
        int i = 10;
        int* p1 = &i;
        *p1 = *p1 * *p1;
        cout << "p1 = " << *p1 << endl;
    }

    {
        double dval = 3.14;
        const double& cdi = dval;
        double& di = dval;

        const int& cri = dval; //编译器产生了一个临时量来完成类型转换
        //int& ri = dval;   //illegal
    }

    {
        int null = 0, *p = &null;
    }
    return 0;
}
