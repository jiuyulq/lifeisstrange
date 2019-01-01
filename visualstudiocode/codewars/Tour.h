// https://www.codewars.com/kata/help-your-granny/cpp
// 2017-11-05 15:54:37  created.

#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

typedef unordered_map<string, double> stringdblmap;
class Tour {
public:
    static int tour(vector<string>& arrFriends, vector<vector<string>>& ftwns, stringdblmap& h);
    static int tour_by_JJoestar(vector<string>& arrFriends, vector<vector<string>>& ftwns, stringdblmap& h);
};

int Tour::tour(vector<string>& arrFriends, vector<vector<string>>& ftwns, stringdblmap& h)
{
    stringdblmap friends_distance; // a map  A*->distance

    stringdblmap::iterator it_dblmap;
    for (unsigned int i = 0; i < ftwns.size(); ++i) {
        it_dblmap = h.find(ftwns.at(i).at(1));
        if (it_dblmap != h.end()) {
            friends_distance.insert({ ftwns.at(i).at(0), it_dblmap->second });
        }
    }

    double tour_distance = 0;

    double second = 0;
    double head = 0;
    for (unsigned int i = 0; i < arrFriends.size(); ++i) {
        if (second == 0) {
            second = friends_distance[arrFriends[i]];
            tour_distance = second;

            continue;
        }

        head = friends_distance[arrFriends[i]];
        if (head == 0)
            continue;

        tour_distance += sqrt(head * head - second * second);
        second = head;
    }

    if (head != 0) {
        tour_distance += head;
    } else {
        tour_distance += second;
    }

    return floor(tour_distance);
}

int Tour::tour_by_JJoestar(vector<string>& arrFriends, vector<vector<string>>& ftwns, stringdblmap& h)
{
    unordered_map<string, string> M;
    for (const auto& x : ftwns)
        M[x[0]] = x[1];
    double t = 0, ans = 0;
    for (const auto& x : arrFriends) {
        if (M.find(x) == M.end())
            continue;
        double d = h[M[x]];
        ans += sqrt(d * d - t * t);
        t = d;
    }
    return int(ans + t);
}

/*

#include "codewars/Tour.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::vector<std::string> friends1 = { "A1", "A2", "A3", "A4", "A5" };
    //std::vector<std::vector<std::string>> fTowns1 = { { "A1", "X1" }, { "A2", "X2" }, { "A3", "X3" }, { "A4", "X4" } };
    std::vector<std::vector<std::string>> fTowns1 = { { "A1", "X1" }, { "A2", "X2" }, { "A3", "X3" } };
    stringdblmap distTable1 = { { "X1", 100.0 }, { "X2", 200.0 }, { "X3", 250.0 }, { "X4", 300.0 } };

    cout << Tour::tour(friends1, fTowns1, distTable1) << endl;
    cout << Tour::tour_by_JJoestar(friends1, fTowns1, distTable1) << endl;
    return 0;
}
*/
