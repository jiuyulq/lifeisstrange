//http://acm.wust.edu.cn/problem.php?cid=1277&pid=13
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

int sum;

void dfs(int** a, int x, int y, int n, int m, int cnt)
{
    a[x][y] = ++cnt;
    if (cnt >= sum) {
        return;
    }
    for (int i = 0; i < m - 1; ++i) {
        y++;
        a[x][y] = ++cnt;
    }
    if (cnt >= sum) {
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        x++;
        a[x][y] = ++cnt;
    }
    if (cnt >= sum) {
        return;
    }
    for (int i = 0; i < m - 1; ++i) {
        y--;
        a[x][y] = ++cnt;
    }
    if (cnt >= sum) {
        return;
    }
    for (int i = 0; i < n - 2; ++i) {
        x--;
        a[x][y] = ++cnt;
    }

    if (cnt >= sum)
        return;
    y++;
    dfs(a, x, y, n - 2, m - 2, cnt);
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
        int** a = new int*[n];
        for (int i = 0; i < n; ++i)
            a[i] = new int[m];
        int cnt = 0;
        sum = n * m;
        dfs(a, 0, 0, n, m, cnt);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << setw(2) << a[i][j];

                if (j != m - 1)
                    cout << " ";
            }
            printf("\n");
        }
    }
    return 0;
}

/*
1  2  3
10 11  4
9 12  5
8  7  6

*/
