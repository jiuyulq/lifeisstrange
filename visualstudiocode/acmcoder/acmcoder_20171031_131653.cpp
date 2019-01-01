// http : //exercise.acmcoder.com/online/online_judge_ques?ques_id=4453&konwledgeId=171
// 2017-10-31 14:01:06
#include <iostream>
#include <string>
using namespace std;

void Submit();
void AfterSubmit();

int main()
{
    //Submit();
    AfterSubmit();

    return 0;
}

void Submit()
{
    string serial_number;
    cin >> serial_number;

    string::iterator it_begin = serial_number.begin();
    string::iterator it_end = serial_number.end();

    int sum = 0;
    for (string::iterator tmp_end = (it_end - 1); tmp_end >= it_begin; tmp_end -= 2) {
        sum += (*tmp_end - '0');
    }

    int double_num;
    for (string::iterator tmp_end = (it_end - 2); tmp_end >= it_begin; tmp_end -= 2) {
        double_num = 2 * (*tmp_end - '0');

        sum += double_num > 9 ? double_num - 9 : double_num;
    }

    if (sum % 10 == 0) {
        cout << "ok" << endl;
    } else {
        cout << "error" << endl;
    }
}

void AfterSubmit()
{
    string serial_number;
    cin >> serial_number;

    int sum = 0;
	int double_num;
    for (int i = 0; i < 16; ++i) {
		if( 0 == i % 2 ){
			double_num = 2 * (serial_number[i] - '0');
	        sum += double_num > 9 ? double_num - 9 : double_num;
		}else{
			sum += (serial_number[i] - '0');
		}
    }

    if (sum % 10 == 0) {
        cout << "ok" << endl;
    } else {
        cout << "error" << endl;
    }
}

//5432123456788881
