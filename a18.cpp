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
            if (j < a[i])
            {
                if (dp[i - 1][j] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            if (j >= a[i])
            {
                if (dp[i - 1][j] == true || dp[i - 1][j - a[i]] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }

    if (dp[n][s] == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}