//https://www.codewars.com/kata/twice-linear/cpp
//2016年11月22日13:10:48

#include<iostream>
#include<set>
#include<algorithm>

using std::cout;
using std::endl;

//by others
class DoubleLinear
{
public:
	static int dblLinear(int n) {
		std::set<int> all{ 1 };
		
		while (n-- > 0) {
			all.insert(*all.begin() * 2 + 1);
			all.insert(*all.begin() * 3 + 1);
			all.erase(all.begin());
		}

		return *all.begin();
	}
};


//Ex: u = [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, ...]

int main() {
	cout << DoubleLinear::dblLinear(5) << endl;
	cout << DoubleLinear::dblLinear(10) << endl;
	cout << DoubleLinear::dblLinear(20) << endl;
	cout << DoubleLinear::dblLinear(30) << endl;
	cout << DoubleLinear::dblLinear(50) << endl;

	return 0;
}

//by jiuyulq
//class DoubleLinear
//{
//public:
//	static vector<int> all;
//
//	static int dblLinear(int n);
//};
//
//vector<int> DoubleLinear::all{ 1 };
//
//int DoubleLinear::dblLinear(int n) {
//	if (n == 0)
//		return 1;
//
//	if ((int)all.size() - 1 - n >= 0)
//		return all.at(n);
//
//	int count = all.size(), num = all.at(count-1) + 1;
//
//	while (count <= n) {
//		if ((num - 1) % 2 == 0  && std::binary_search(all.begin(), all.end(), (num - 1) / 2)) {
//				all.push_back(num++);
//				count++;
//				continue;
//		}
//		
//		if ((num - 1) % 3 == 0  && std::binary_search(all.begin(), all.end(), (num - 1) / 3)) {
//				all.push_back(num++);
//				count++;
//				continue;
//		}
//
//		num++;
//	}
//	return --num;
//}
