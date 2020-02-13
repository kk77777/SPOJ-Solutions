#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(ll s, bool visited[], vector<ll> adj[], ll n)
{
    visited[s] = true;

    for (int i = 0; i < adj[s].size(); ++i)
    {
        if (visited[adj[s][i]] == false)
            dfs(adj[s][i], visited, adj, n);
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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, e;
        cin >> n >> e;
        vector<ll> adj[n];
        ll a, b, c = 0;
        bool visited[n] = {false};

        for (int i = 0; i < e; ++i)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj, n);
                c++;
            }
        }
        cout << c << "\n";
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}
