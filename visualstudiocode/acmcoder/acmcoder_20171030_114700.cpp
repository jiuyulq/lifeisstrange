#include <iostream>
#include <string>
using namespace std;

bool EraseChar(string& str, string::iterator& it_pos); // erase a char from str which equals to *it_pos.

int main()
{
	string str_a, str_b;
	cin >> str_a >> str_b;

	string::iterator it_begin = str_b.begin();
	string::iterator it_end = str_b.end();

	for (; it_begin != it_end; ++it_begin) {
		if (!EraseChar(str_a, it_begin)) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;

	cout << str_a << endl;

	return 0;
}

bool EraseChar(string& str, string::iterator& it_pos)
{
	string::iterator str_begin = str.begin();
	string::iterator str_end = str.end();
		for (; str_begin != str_end; ++str_begin) {
			if (*str_begin == *it_pos) {
				str.erase(str_begin);
				return true;
			}
		}

	return false;
}

/*
fjdskl人
人f

aaaabbbcccdddss
abc
*/
