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

    ll n, k, ans = 0, temp;
    cin >> n >> k;

    vector<ll> v;
    unordered_map<ll, ll> ct;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ct[temp]++;
        v.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        ans += ct[v[i] + k];
        ans += ct[v[i] - k];
    }
    ans = ans / 2;
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}