#include <bits/stdc++.h>
#define ll long long int
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

    ll n, m;
    cin >> n >> m;
    ll a[n], maxa = -1, lb = 0, ub, total = 0, mid, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > maxa)
        {
            maxa = a[i];
        }
    }
    ub = maxa;

    while (lb <= ub)
    {
        total = 0;
        mid = (lb + ub) / 2;
        for (auto i = 0; i < n; i++)
        {
            ll temp = a[i] - mid;
            total += (temp > 0 ? temp : 0);
        }
        if (total == m)
        {
            ans = mid;
            break;
        }
        else if (total < m)
        {
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
            if (mid > ans)
            {
                ans = mid;
            }
        }
    }
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}