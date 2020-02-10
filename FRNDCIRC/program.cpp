#include <bits/stdc++.h>
#define ll long long
#define max 1000000
using namespace std;

map<string, int> v;
unordered_map<string, string> visit;

string find_set(string x)
{

    while (x != visit[x])
    {
        visit[x] = visit[visit[x]];
        x = visit[x];
    }
    return x;
}

void union_sets(string a, string b)
{
    visit[(b)] = (a);
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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        visit.clear();
        v.clear();

        while (n--)
        {
            string a, b;
            cin >> a >> b;

            if (!v[a])
            {
                v[a] = 1;
                visit[a] = a;
            }
            if (!v[b])
            {
                v[b] = 1;
                visit[b] = b;
            }
            string ra, rb;
            ra = find_set(a);
            rb = find_set(b);
            if (ra != rb)
            {
                union_sets(ra, rb);
                v[ra] = v[ra] + v[rb];
            }
            cout << v[ra] << "\n";
        }
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}