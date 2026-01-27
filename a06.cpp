#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n), pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        pre[i] = a[i - 1] + pre[i - 1];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}
