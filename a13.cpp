#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            r[i] = 0;
        }
        else
        {
            r[i] = r[i - 1];
        }

        while (r[i] + 1 < n && a[r[i] + 1] - a[i] <= k)
        {
            r[i]++;
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += r[i] - i;
    }

    cout << ans << endl;

    return 0;
}
