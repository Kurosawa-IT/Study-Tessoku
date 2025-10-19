#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }

    vector<int> sum(n + 1);
    sum.at(0) = 0;

    for (int i = 1; i < n + 1; i++)
    {
        sum.at(i) = a.at(i - 1) + sum.at(i - 1);
    }

    vector<int> l(q), r(q);

   for (int i = 0; i < q; i++)
    {
        cin >> l.at(i) >> r.at(i);
    }

    for (int i = 0; i < q; i++)
    {
        cout << sum.at(r.at(i)) - sum.at(l.at(i) - 1) << endl;
    }
}
