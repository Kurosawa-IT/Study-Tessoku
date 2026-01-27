#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<long long>> x(h + 1, vector<long long>(w + 1)), prefix(h + 1, vector<long long>(w + 1));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> x[i][j];
            prefix[i][j] = x[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << prefix[c][d] + prefix[a - 1][b - 1] - prefix[a - 1][d] - prefix[c][b - 1] << endl;
    }

    return 0;
}
