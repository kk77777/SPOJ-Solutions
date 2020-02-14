#include <bits/stdc++.h>
#define ll long long int
#define M 1000000
using namespace std;

ll parent[M + 10];
ll sz[M + 10];
ll rk[M + 10];
multiset<ll> s;

ll find_set(ll x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(ll x, ll y)
{
    x = find_set(x);
    y = find_set(y);
    if (x == y)
        return;
    if (rk[x] < rk[y])
        swap(x, y);
    if (rk[x] == rk[y])
        rk[x]++;
    s.erase(s.find(sz[x]));
    s.erase(s.find(sz[y]));
    sz[x] += sz[y];
    s.insert(sz[x]);
    parent[y] = x;
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

    ll n, q;
    cin >> n >> q;

    for (auto i = 1; i <= n; ++i)
    {
        parent[i] = i;
        sz[i] = 1;
        s.insert(1);
    }

    for (int i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        union_set(a, b);
        cout << *(--s.end()) - *(s.begin()) << "\n";
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}