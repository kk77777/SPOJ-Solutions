#include <bits/stdc++.h>
using namespace std;

int dr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dc[] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool vis[51][51];
int level[51][51];
int res = 0;
int r, c;
void bfs(pair<int, int> v, int s, char a[51][51])
{

    vis[v.first][v.second] = true;
    level[v.first][v.second] = 1;
    queue<pair<int, int>> q;
    q.push(v);
    // int lpath;
    while (!q.empty())
    {
        pair<int, int> p = q.front();

        q.pop();
        for (auto i = 0; i < 8; ++i)
        {
            int x = p.first + dr[i];
            int y = p.second + dc[i];

            if (x >= r || x < 0 || y >= c || y < 0)
                continue;

            if (vis[x][y])
                continue;

            if (a[x][y] == ((a[p.first][p.second]) + 1))
            {

                vis[x][y] = true;
                level[x][y] = level[p.first][p.second] + 1;
                if (level[x][y] > res)
                {
                    res = level[x][y];
                }
                q.push(make_pair(x, y));
            }
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
    int cs = 0;
    while (1)
    {
        cin >> r >> c;
        if (r == 0 && c == 0)
            break;
        cs++;
        res = 0;

        vector<pair<int, int>> v;
        pair<int, int> x;
        vector<pair<int, int>> p;
        char s[51][51];
        for (int i = 0; i < r; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < c; j++)
            {
                s[i][j] = str[j];
                if (str[j] == 'A')
                {
                    level[i][j] = 1;
                    if (res == 0)
                        res++;
                    v.push_back(make_pair(i, j));
                }
            }
        }
        for (auto i = 0; i < v.size(); ++i)
        {
            memset(level, 0, sizeof level);
            memset(vis, false, sizeof vis);
            bfs(v[i], i, s);
        }
        cout << "Case " << cs << ": " << res << "\n";
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}
