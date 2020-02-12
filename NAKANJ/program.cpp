#include <bits/stdc++.h>
using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool visited[9][9];

bool valid(int x, int y)
{
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
        return true;
    return false;
}

int bfs(pair<pair<int, int>, int> s, pair<pair<int, int>, int> d)
{
    visited[s.first.first][s.first.second] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push(s);
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        if (d.first.first == p.first.first && d.first.second == p.first.second)
        {
            return p.second;
        }
        for (int i = 1; i <= 8; ++i)
        {
            pair<int, int> a;
            a.first = p.first.first + dx[i - 1];
            a.second = p.first.second + dy[i - 1];
            if (!visited[a.first][a.second])
            {
                if (valid(a.first, a.second))
                {
                    visited[a.first][a.second] = true;
                    q.push(make_pair(a, p.second + 1));
                }
            }
        }
    }
    return INT_MAX;
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
        string a, b;
        pair<pair<int, int>, int> s, d;
        cin >> a >> b;
        int x, y;
        x = a[0] - 96;
        y = a[1] - 48;
        int dist = 0;
        s = make_pair(make_pair(x, y), dist);

        x = b[0] - 96;
        y = b[1] - 48;
        d = make_pair(make_pair(x, y), dist);
        memset(visited, false, sizeof(visited));
        cout << bfs(s, d) << "\n";
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}
