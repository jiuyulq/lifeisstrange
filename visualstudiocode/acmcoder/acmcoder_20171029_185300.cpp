// http://exercise.acmcoder.com/online/online_judge_ques?ques_id=1662&konwledgeId=135
// 2017-10-29 19:20:57 passed
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int box_num, opr_num;
    cin >> box_num >> opr_num;

    int* boxes = new int[box_num];
    for (int i = 0; i < box_num; ++i) {
        cin >> boxes[i];
    }

    int opr_choose;
    int box_range_start, box_range_end;

    for (int i = 0; i < opr_num; ++i) {
        cin >> opr_choose >> box_range_start >> box_range_end;
        box_range_start -= 1;
        box_range_end -= 1;

        if (box_range_start > box_range_end) {
            box_range_start ^= box_range_end;
            box_range_end ^= box_range_start;
            box_range_start ^= box_range_end;
        }

        switch (opr_choose) {
        case 1:
            break;
        case 2: {
            int weight_sum = 0;
            for (; box_range_start <= box_range_end; ++box_range_start) {
                weight_sum += boxes[box_range_start];
            }
            cout << weight_sum << endl;
        } break;
        case 3: {
            int weight_max = boxes[box_range_start++];
            for (; box_range_start <= box_range_end; ++box_range_start) {
                if (boxes[box_range_start] > weight_max)
                    weight_max = boxes[box_range_start];
            }
            cout << weight_max << endl;
        } break;
        default:
            break;
        }
    }

    return 0;
}
