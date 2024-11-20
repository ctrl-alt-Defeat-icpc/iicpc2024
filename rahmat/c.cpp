#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 50 + 5;
int n, a, b;
bool d[N][N];
int p, remindp, row, col, column_in_last, lastPoint;

void fillSquar(int x, int y) {
    d[x][y + 1] = d[x + 2][y + 1] = d[x + 1][y] = d[x + 1][y + 1] = d[x + 1][y + 2] = 1;
}

void Main() {
    cin >> n;
    p = n / 4;
    lastPoint = n % 4;
    row = p / 11;
    column_in_last = p % 11;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < 11; j++) {
            fillSquar(i * 4, j * 4);
        }
    for(int i = 0; i < column_in_last; i++)
        fillSquar(row * 4, i * 4);

    if(lastPoint) {
        d[49][49] = d[49][48] = 1;
        for(int i = 0; i < lastPoint; i++)
            d[49][47 - i] = 1;
    }


    a = b = 50;
    cout << a << " " << b << '\n';
    for(int i = 0; i < a; i++, cout << '\n')
        for(int j = 0; j < b; j++)
            if(d[i][j]) cout << 'X';
            else cout << '.';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        Main();
    return 0;
}
