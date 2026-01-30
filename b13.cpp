#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            r[i] = 1;
        }
        else
        {
            r[i] = r[i - 1];
        }

        while (r[i] + 1 <= n && prefix[r[i] + 1] - prefix[i - 1] <= k)
        {
            r[i]++;
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += r[i] - i + 1;
    }

    cout << ans << endl;

    return 0;
}
