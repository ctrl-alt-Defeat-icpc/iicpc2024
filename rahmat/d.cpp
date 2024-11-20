#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int N = 1e6 + 5;
int n, q, cur, dcur, dcur_neg;
string choice;
ull server[N], ans, value, diag;

void Main() {
    cin >> n >> q;
    while(q--) {
        cin >> choice;
        if(choice[0] == 'a') {
            cin >> value;
            server[cur++] = value;
            ans += value;
        }
        else {
            if(dcur < cur)
                diag += server[dcur++];
            if(dcur <= n && dcur_neg < dcur)
                diag -= server[dcur_neg++];
            
            ans += diag;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        Main();
    return 0;
}
