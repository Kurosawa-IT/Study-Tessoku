#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> area(1509, vector<int>(1509 ,0));
    vector<vector<int>> prefix(1509, vector<int>(1509, 0));

    int a, b, c, d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c >> d;

        area.at(a).at(b) += 1;
        area.at(a).at(d) -= 1;
        area.at(c).at(b) -= 1;
        area.at(c).at(d) += 1;
    }

    // 横方向累積和
    for (int i = 1; i < 1509; i++)
    {
        for (int j = 1; j < 1509; j++)
        {
            prefix.at(i).at(j) = prefix.at(i).at(j - 1) + area.at(i).at(j);
        }
    }

    // 縦方向累積和
    for (int j = 1; j < 1509; j++)
    {
        for (int i = 1; i < 1509; i++)
        {
            prefix.at(i).at(j) += prefix.at(i - 1).at(j);
        }
    }

    int count = 0;

    // カウント
    for (int i = 1; i < 1509; i++)
    {
        for (int j = 1; j < 1509; j++)
        {
            if (prefix.at(i).at(j) > 0) count++;
        }
    }

    cout << count << endl;

    return 0;
}
