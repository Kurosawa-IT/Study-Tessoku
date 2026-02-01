#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = true;
            }

            if (j >= a[i] && dp[i - 1][j - a[i]])
            {
                dp[i][j] = true;
            }
        }
    }

    if (dp[n][s] == false)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    int place = s;

    for (int i = n; i >= 1; i--)
    {
        if (place >= a[i] && dp[i - 1][place - a[i]])
        {
            place = place - a[i];
            ans.push_back(i);
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}