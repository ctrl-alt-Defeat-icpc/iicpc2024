#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

void Main()
{
    int n;
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c || a == d || b == c || b == d)
        cout << 3;
    else if ((a < c && a > d) || (b < c && b > d))
        cout << 3;
    else if ((a > c && a < d) || (b > c && b < d))
        cout << 3;
    else
        cout << 4;
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