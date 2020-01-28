#include <bits/stdc++.h>
using namespace std;

int m, n;
bool vis[260][260];
map<int, int> v;
int c = 0;
int a[260][260];
int dfs(int x, int y)
{

    if (x >= n || y >= m)
        return 0;
    if (x < 0 || y < 0)
        return 0;
    if (a[x][y] == 0)
        return 0;
    if (vis[x][y])
        return 0;
    vis[x][y] = true;
    c++;
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x + 1, y);

    return 0;
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

    int t = 1;
    while (t)
    {
        memset(vis, false, sizeof(vis));
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j])
                {
                    c = 0;
                    int z = dfs(i, j);
                    if (c != 0)
                    {
                        if (v.find(c) != v.end())
                        {
                            v[c]++;
                        }
                        else
                        {
                            v.insert(pair<int, int>(c, 1));
                        }
                    }
                }
            }
        }
        map<int, int>::iterator it;
        int nt = 0;
        for (it = v.begin(); it != v.end(); ++it)
        {
            nt += (*it).second;
        }
        cout << nt << "\n";
        for (it = v.begin(); it != v.end(); ++it)
        {
            cout << (*it).first << " " << (*it).second << '\n';
        }
        v.clear();
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}