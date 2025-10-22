#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a.at(i);
    }

    vector<int> prefix(n + 1);
    prefix.at(0) = a.at(0);

    for (int i = 1; i <= n; i++)
    {
        prefix.at(i) = prefix.at(i - 1) + a.at(i);
    }

    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            r.at(0) = 0;
        else
            r.at(i) = r.at(i - 1);

        while (r.at(i) < n && prefix.at(r.at(i) + 1) - prefix.at(i - 1) <= k)
        {
            r.at(i)++;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += r.at(i) - i + 1;

    cout << ans << endl;
}