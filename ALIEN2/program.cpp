#include <bits/stdc++.h>
#define ll long long
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

    ll n, k;
    cin >> n >> k;
    ll a[n], b[n];
    for (auto i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (auto i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll stnCount = 1;
    for (auto i = 1; i < n; i++)
    {
        ll temp = a[i];
        a[i] = min(a[i - 1] + a[i], b[i - 1] + b[i] + a[i]);
        b[i] = min(b[i - 1] + b[i], a[i - 1] + temp + b[i]);

        // cout << "a[" << i << "] = " << a[i] << "\n";
        // cout << "b[" << i << "] = " << b[i] << "\n";
        if (min(a[i], b[i]) > k)
        {
            break;
        }
        stnCount++;
    }
    ll ns, cnt;
    if (stnCount != n)
    {
        // cout << "yes\n";
        ns = stnCount;
        cnt = min(a[stnCount - 1], b[stnCount - 1]);
    }
    else
    {
        ns = n;
        cnt = min(a[n - 1], b[n - 1]);
    }
    cout << ns << " " << cnt;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}