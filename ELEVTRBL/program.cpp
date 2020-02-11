#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define max 1000010

bool vis[max];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));

    while (!q.empty())
    {
        ll cf = q.front().first;
        ll cl = q.front().second;
        q.pop();
        if (vis[cf] == true)
            continue;
        vis[cf] = true;
        if (cf == g)
        {
            cout << cl << "\n";
            return 0;
        }
        if (cf + u <= f)
        {
            q.push(make_pair(cf + u, cl + 1));
        }
        if (cf - d > 0)
        {
            q.push(make_pair(cf - d, cl + 1));
        }
    }
    cout << "use the stairs\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}