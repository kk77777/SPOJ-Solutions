#include <bits/stdc++.h>
#define ll long int
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
    bool flag = true;

    while (flag)
    {
        int n, cnt = 0;
        cin >> n;
        if (n == 0)
        {
            flag = 0;
            break;
        }

        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);
        for (int i = n - 1; i > 1; i--)
        {
            int j = 0, k = i - 1;
            while (j < k)
            {
                if (a[i] > a[j] + a[k])
                {
                    cnt += k - j;
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        cout << cnt << "\n";
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}