#include <bits/stdc++.h>
#define ll long int
#define M 1000000
using namespace std;

ll n, m;
int parent[M + 10];
int s[M + 10];

int find_set(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = find_set(parent[a]);
}

void make_set(int a)
{
    parent[a] = a;
    s[a] = 1;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    // cout << "a = " << a << " & b = " << b << "\n";
    if (a != b)
    {
        if (s[a] + s[b] <= m)
        {
            if (s[a] < s[b])
                swap(a, b);
            parent[b] = a;
            s[a] += s[b];
            // cout << "(" << a << "," << b << ")";
        }
    }
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

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        make_set(i);
    }

    ll q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        if (c == 'A')
        {
            // cout << c << "\n";
            ll a, b;
            cin >> a >> b;
            union_sets(a, b);
        }
        if (c == 'E')
        {
            // cout << c << "\n";
            ll a, b;
            cin >> a >> b;
            a = find_set(a);
            b = find_set(b);

            // cout << a << "\n";
            // cout << b << "\n";
            if (a == b)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        if (c == 'S')
        {
            // cout << c << "\n";
            ll x;
            cin >> x;
            ll a = find_set(x);
            cout << s[a] << "\n";
            // cout << s[x] << "\n";
        }
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}