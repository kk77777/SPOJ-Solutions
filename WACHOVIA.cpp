#include <bits/stdc++.h>
using namespace std;

int t[1005][1005];

int solve(int wt[], int val[], int w, int n)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
        }
    }

    return t[n][w];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(t, -1, sizeof t);
        int w, n;
        cin >> w >> n;
        int wt[1005], val[1005];
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i] >> val[i];
        }

        cout << "Hey stupid robber, you can get " << solve(wt, val, w, n) << ".\n";
    }
}