#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }

    int l = 0, r = n - 1, m = (l + r) / 2;

    while (l <= r)
    {
        m = (l + r) / 2;
        if (a.at(m) == x)
            break;
        if (a.at(m) > x)
            r = m - 1;
        if (a.at(m) < x)
            l = m + 1;
    }

    cout << m + 1 << endl;

    return 0;
}
