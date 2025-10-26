#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++)
    {
        cin >> a.at(i);
    }
    for (int i = 2; i < n; i++)
    {
        cin >> b.at(i);
    }

    vector<int> dp(n);
    dp.at(0) = 0;
    dp.at(1) = a.at(1);

    for (int i = 2; i < n; i++)
    {
        dp.at(i) = min(a.at(i) + dp.at(i - 1), b.at(i) + dp.at(i - 2));
    }

    cout << dp.at(n - 1) << endl;
    return 0;
}
