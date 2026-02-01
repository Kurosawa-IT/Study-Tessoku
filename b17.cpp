#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    int place = n - 1;
    vector<int> ans;

    while (true)
    {

        ans.push_back(place);
        if (place == 0)
            break;

        if (dp[place - 1] + abs(h[place] - h[place - 1]) == dp[place])
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