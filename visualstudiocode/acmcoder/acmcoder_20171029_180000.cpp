// http://exercise.acmcoder.com/online/online_judge_ques?ques_id=1677&konwledgeId=135
// 2017-10-29 18:22:18 passed
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str_a;
    string str_b;
    cin >> str_a >> str_b;

    int str_len = str_a.length();
    int str_same_count = 0;

    char ch;
    for (int i = 0; i < str_len; ++i) {
        ch = str_a.at(i);
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            if (str_b.at(i) == '1')
                ++str_same_count;
        } else {
            if (str_b.at(i) == '0')
                ++str_same_count;
        }
    }
    cout << fixed << setprecision(2) << (str_same_count * 1.0 / str_len) * 100
         << "%" << endl;

    return 0;
}
