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

    long long neg_inf = LLONG_MIN / 4;
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, neg_inf));

    dp[0][0] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= w[i] && dp[i - 1][j - w[i]] != neg_inf)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= W; i++)
    {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;

    return 0;
}