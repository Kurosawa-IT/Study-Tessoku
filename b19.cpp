#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;

    vector<int> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }

    long long inf = LLONG_MAX / 4;
    vector<vector<long long>> dp(N + 1, vector<long long>(100001, inf));

    dp[0][0] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= 100000; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= v[i] && dp[i - 1][j - v[i]] != inf)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= 100000; i++)
    {
        if (dp[N][i] <= W) {
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}