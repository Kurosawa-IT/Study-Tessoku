#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<int>> prefix(h + 1, vector<int>(w + 1));

    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;

        prefix[a][b]++;
        prefix[c + 1][d + 1]++;
        prefix[a][d + 1]--;
        prefix[c + 1][b]--;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i > 0) prefix[i][j] += prefix[i - 1][j];
            if (j > 0) prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
