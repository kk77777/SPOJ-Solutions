#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll n, ll *c)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return c[0];
    if (n == 2)
        return max(c[0], c[1]);

    ll dp[n];
    dp[0] = c[0];
    dp[1] = max(c[0], c[1]);

    for (auto i = 2; i < n; i++)
    {
        dp[i] = max(c[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n - 1];
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
    ll cnt = 0;
    while (t--)
    {
        cnt++;
        ll n;
        cin >> n;
        ll c[n];
        for (auto i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        ll ans = f(n, c);
        cout << "Case " << cnt << ": " << ans << "\n";
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}