#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> area(1509, vector<int>(1509));
    vector<vector<int>> prefix(1509, vector<int>(1509, 0));

    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        area.at(a).at(b) += 1;
        area.at(c + 1).at(d + 1) += 1;
        area.at(a).at(d + 1) -= 1;
        area.at(c + 1).at(b) -= 1;
    }

    // 横方向累積和
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            prefix.at(i).at(j) = prefix.at(i).at(j - 1) + area.at(i).at(j);
        }
    }

    // 縦方向累積和
    for (int j = 1; j <= w; j++)
    {
        for (int i = 1; i <= h; i++)
        {
            prefix.at(i).at(j) += prefix.at(i - 1).at(j);
        }
    }

    // 出力
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cout << prefix.at(i).at(j);
            if (j == w)
                cout << endl;
            else
                cout << " ";
        }
    }

    return 0;
}