#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
int n, m;
pair<int, int> h[N];
ll ans;

bool compare2(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

bool compare1(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first != b.first) return a.first > b.first;
    return compare2(a, b);
}

void Main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> h[i].first >> h[i].second;
    
    sort(h, h + n, compare1);
    if(n > m)
        sort(h + m, h + n, compare2);

    int i;
    for(i = 0; i < m && i < n; i++)
        ans += h[i].first;
    for(; i < n; i++)
        ans += h[i].second;

    cout << ans << '\n';

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
