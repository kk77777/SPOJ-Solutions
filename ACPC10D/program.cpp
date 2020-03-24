#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll cnt = 0;
    while (1)
    {
        cnt++;
        ll n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        ll a[n + 5][3];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
            }
        }
        if (n == 1)
        {
            cout << a[0][1] << "\n";
        }
        else
        {

            a[0][2] += a[0][1];
            a[1][0] += a[0][1];

            a[1][1] += min(min(a[1][0], a[0][1]), a[0][2]);
            a[1][2] += min(min(a[1][1], a[0][1]), a[0][2]);

            for (auto i = 2; i < n; i++)
            {
                a[i][0] += min(a[i - 1][0], a[i - 1][1]);
                a[i][1] += min(min(a[i][0], a[i - 1][0]), min(a[i - 1][1], a[i - 1][2]));
                a[i][2] += min(min(a[i][1], a[i - 1][1]), a[i - 1][2]);
            }

            cout << cnt << ". " << a[n - 1][1] << "\n";
        }
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}