#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> prefix(1501, vector<int>(1501));

    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        prefix[a][b]++;
        prefix[c][d]++;
        prefix[a][d]--;
        prefix[c][b]--;
    }

    int cnt = 0;

    for (int i = 0; i < 1500; i++)
    {
        for (int j = 0; j < 1500; j++)
        {
            if (i > 0)
                prefix[i][j] += prefix[i - 1][j];
            if (j > 0)
                prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0)
                prefix[i][j] -= prefix[i - 1][j - 1];
            if (prefix[i][j] > 0)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
