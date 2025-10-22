#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }

    vector<int> r(n);
    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
            r.at(i) = 0;
        else
            r.at(i) = r.at(i - 1);

        while (r.at(i) < n - 1 && a.at(r.at(i) + 1) - a.at(i) <= k)
        {
            r.at(i)++;
        }
    }

    long long ans = 0;

    for (int i = 0; i < n - 1; i++)
        ans += r.at(i) - i;
    cout << ans << endl;
    return 0;
}
