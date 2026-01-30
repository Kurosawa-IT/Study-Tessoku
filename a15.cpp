#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), t(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        t.push_back(a[i]);
    }

    sort(t.begin(), t.end());

    t.erase(unique(t.begin(), t.end()), t.end());

    for (int i = 0; i < n; i++)
    {
        b[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin();
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;

    return 0;
}