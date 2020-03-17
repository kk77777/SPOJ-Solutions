#include <bits/stdc++.h>
#define ll long long int
#define inf 1000000000
#define maxn 50000
using namespace std;

ll a[maxn];
ll n;

bool dis(ll mid, ll per)
{
    for (auto i = 0; i < n; i++)
    {
        per -= a[i] / mid;
        if (per < 1)
            return true;
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
        ll k;
        cin >> n >> k;

        memset(a, 0, sizeof a);

        ll max = -inf;

        for (auto i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > max)
            {
                max = a[i];
            }
        }

        ll lb = 0, ub = max;

        while (lb < ub)
        {
            ll mid = lb + (ub - lb + 1) / 2;
            if (dis(mid, k))
            {
                lb = mid;
            }
            else
            {
                ub = mid - 1;
            }
        }
        cout << lb << "\n";
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}