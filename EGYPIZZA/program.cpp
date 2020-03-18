#include <bits/stdc++.h>
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

    int n, cnt = 0;
    cin >> n;
    int a[3];
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[0] == '1' && s[2] == '4')
        {
            a[0]++;
        }
        if (s[0] == '1' && s[2] == '2')
        {
            a[1]++;
        }
        if (s[0] == '3' && s[2] == '4')
        {
            a[2]++;
        }
    }

    cnt = a[1] / 2;
    a[1] = a[1] % 2;

    int x = min(a[0], a[2]);
    cnt += x;
    a[0] -= x;
    a[2] -= x;

    if (a[1] && a[0] >= 2)
    {
        a[0] -= 2;
        a[1] = 0;
    }
    cnt += a[0] / 4;
    a[0] = a[0] % 4;
    if (a[0] || a[1])
    {
        cnt++;
    }
    cnt += a[2];

    cout << cnt + 1;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}