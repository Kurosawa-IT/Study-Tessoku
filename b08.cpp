#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<long long>> prefix(1501, vector<long long>(1501));

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        prefix[x][y]++;
    }

    for (int i = 1; i < 1501; i++) {
        for (int j = 1; j < 1501; j++) {
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << prefix[c][d] + prefix[a - 1][b - 1] - prefix[a - 1][d] - prefix[c][b - 1] << endl;
    }

    return 0;
}
