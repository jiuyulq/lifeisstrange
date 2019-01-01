#include <iostream>
#include <vector>
using namespace std;

int main()
{
    {
        //数组初始化vector.
        int int_arr[]{ 1, 2, 3, 4 };
        std::vector<int> v_int(begin(int_arr), end(int_arr));
        std::vector<int> v_int2(int_arr, int_arr + 2);

        int_arr[1] = 20;

        for (auto i : int_arr) {
            std::cout << i << '\n';
        }

        for (auto i : v_int) {
            std::cout << i << '\n';
        }

        for (auto i : v_int2) {
            std::cout << i << '\n';
        }
    }

    {
        //使用范围for语句处理多维数组，除了最内存循环，其他所有循环的控制变量都应该使用引用类型
    }

    //2018-01-28 14:13:09
    {
        //内联函数(inline)只是向编译器发出的一个请求，编译器可以选择忽略.
    }

    {
        //page 216
        //__func__    编译器定义的静态数字，存放当前函数的名字
        //预处理器定义的对于调试程序有用的变量
        //__FILE__,__LINE__,__TIME__,__DATE__
    }

    return 0;
}
