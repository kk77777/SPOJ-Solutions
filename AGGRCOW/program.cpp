#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll n, ll c, ll mid, ll pos[])
{
    ll cnt = 1;
    ll last = pos[0];
    for (auto i = 1; i < n; i++)
    {
        if (pos[i] - last >= mid)
        {
            cnt++;
            last = pos[i];
        }
        if (cnt == c)
        {
            return true;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, c, ans;
        cin >> n >> c;
        ll pos[n];
        for (auto i = 0; i < n; i++)
        {
            cin >> pos[i];
        }
        sort(pos, pos + n);
        ll lb = 0;
        ll ub = pos[n - 1] - pos[0];
        while (lb <= ub)
        {
            ll mid = lb + (ub - lb + 1) / 2;
            if (check(n, c, mid, pos))
            {
                ans = mid;
                lb = mid + 1;
            }
            else
            {
                ub = mid - 1;
            }
        }
        cout << ans << "\n";
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}