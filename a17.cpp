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

    vector<int> ans;
    int place = n - 1;

    while (true)
    {
        ans.emplace_back(place + 1);
        if (place == 0)
            break;

        if (dp.at(place - 1) + a.at(place) == dp.at(place))
        {
            place = place - 1;
        }
        else
        {
            place = place - 2;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }
    cout << endl;

    return 0;
}
