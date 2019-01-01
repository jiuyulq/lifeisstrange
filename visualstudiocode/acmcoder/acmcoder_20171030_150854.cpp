// http://exercise.acmcoder.com/online/online_judge_ques?ques_id=1683&konwledgeId=135
// 2017-10-30 17:06:55
#include <iostream>
#include <vector>
using namespace std;

void MoveTo(vector<int> &to, vector<int> &from);
bool FindInVector(vector<int> &vec, int val);

int main()
{
	int n, m;
	while (cin >> n >> m) {
		if (0 == n && 0 == m) {
			break;
		}
		vector<vector<int>> infos(n);

		int person_a, person_b;
		//read and store
		for (int i = 0; i < n; ++i) {
			infos[i].push_back(i + 1);
		}

		for (int i = 0; i < m; ++i) {
			cin >> person_a >> person_b;
			infos[person_a - 1].push_back(person_b);
		}

		//process
		for (int pos = 0; pos != infos[0].size(); ++pos) {
			for (int i = 1; i < n; ++i) {
				if (FindInVector(infos[i], infos[0][pos])) {
					MoveTo(infos[0], infos[i]);
				}
			}
		}

		cout << infos[0].size() - 1 << endl;
	}
	
	return 0;
}

void MoveTo(vector<int> &to, vector<int> &from) {
	for (auto val : from) {
		if (!FindInVector(to, val)) {
			to.push_back(val);
		}
	}
	from.clear();
}

bool FindInVector(vector<int> &vec, int val) {
	if (vec.empty())
		return false;

	auto it_begin = vec.begin();
	auto it_end = vec.end();
	for (; it_begin != it_end; ++it_begin) {
		if (*it_begin == val)
			return true;
	}

	return false;
}
