#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n, 0), b(n, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i]);
    }

    int place = n - 1;
    vector<int> ans;
    while (true)
    {
        ans.push_back(place);
        if (place == 0)
            break;

        if (dp[place - 1] + a[place] == dp[place])
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
        cout << ans[i] + 1 << " ";
    }

    cout << endl;

    return 0;
}