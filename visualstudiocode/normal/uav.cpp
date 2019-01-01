#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void checkUAV(string file_name, int index)
{
    if (index < 0) {
        cout << "Cannot find " << index << endl;
        return;
    }

    ifstream file(file_name);

    string line;
    vector<vector<int>> plane_log;
    string plane_name;
    int line_index = -1;
    int x, y, z, offset_x, offset_y, offset_z;
    bool log_status = true;

    //读取第一行
    if (getline(file, line)) {
        istringstream issline(line);
        issline >> plane_name >> x >> y >> z;
        vector<int> v = { x, y, z };
        line_index++;
        plane_log.push_back(v);
    } else { //第一行不存在
        cout << "Cannot find " << index << endl;
        return;
    }

    //读取剩余所有行
    while (getline(file, line)) {
        if (!log_status) { //如果当前行无效，则不记录数据，仅仅增加行数。
            line_index++;
            continue;
        }

        istringstream issline(line);
        if (!(issline >> plane_name >> x >> y >> z
                >> offset_x >> offset_y >> offset_z)) { //如果当前行数据格式不正确。
            line_index++;
            log_status = false;
            continue;
        }

        if (plane_log[line_index][0] != x
            || plane_log[line_index][1] != y
            || plane_log[line_index][2] != z) { //如果当前行起始位置与上一记录不符合。
            line_index++;
            log_status = false;
            continue;
        }

        //记录下正确的位置数据
        vector<int> v = { x + offset_x, y + offset_y, z + offset_z };
        line_index++;
        plane_log.push_back(v);
    }

    //输出结果
    if (index > line_index) {
        cout << "Cannot find " << index << endl;
    } else if (index > plane_log.size() - 1) {
        cout << "Error: " << index << endl;
    } else {
        cout << plane_name << " " << index
             << " " << plane_log[index][0]
             << " " << plane_log[index][1]
             << " " << plane_log[index][2] << endl;
    }
}

int main()
{
    cout << "===test one===" << endl;
    checkUAV("plane1.log", 1);
    checkUAV("plane1.log", 2);
    checkUAV("plane1.log", 4);
    checkUAV("plane1.log", 100);
    cout << "===test two===" << endl;
    checkUAV("plane2.log", 0);
    checkUAV("plane2.log", 1);
    checkUAV("plane2.log", 2);
    checkUAV("plane2.log", 3);
    checkUAV("plane2.log", 4);
    checkUAV("plane2.log", -1);
    checkUAV("plane2.log", 100);
    return 0;
}
