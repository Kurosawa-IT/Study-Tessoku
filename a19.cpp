#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> w.at(i) >> v.at(i);
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1));
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp.at(i).at(j) = -1000000000000000;
        }
    }

    dp.at(0).at(0) = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp.at(i).at(j) = dp.at(i - 1).at(j);
            if (j >= w.at(i))
                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - 1).at(j - w.at(i)) + v.at(i));
        }
    }

    long long ans = 0;
    for (int i = 0; i <= W; i++)
        ans = max(ans, dp.at(N).at(i));
    cout << ans << endl;
    return 0;
}
