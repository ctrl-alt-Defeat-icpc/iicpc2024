#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int N = 1e6 + 5;
int n, q, ser1size; // server 1 size
int sync_left, sync_right, sync_depth, first_added_sync, last_added_sync;
queue<int> diff;
string choice;
ull server[N], ans, value, sync_value;

void Main() {
    cin >> n >> q;
    while(q--) {
        cin >> choice;
        if(choice[0] == 'a') {
            cin >> value;
            server[ser1size++] = value;
            ans += value;
        }
        else {
            if(sync_right < ser1size) { // an element added to sync
                sync_value += server[sync_right++];
                if(first_added_sync != -1) { // sync is not empty
                    diff.push(last_added_sync);
                    last_added_sync = 0;
                }
                else
                    first_added_sync = last_added_sync = 0;
            }

            first_added_sync++;
            last_added_sync++;

            ans += sync_value;
            // cout << "sync: " << ans << ' ' << sync_value << " =>" << "l:" << sync_left << " r:" << sync_right << " " << first_added_sync << " " << last_added_sync << '\n';

            if(first_added_sync == n - 1) {
                first_added_sync = n - 1 - diff.front();
                diff.pop();
                if(sync_left < sync_right)
                    sync_value -= server[sync_left++];
            }
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
