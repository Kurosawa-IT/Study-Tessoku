#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a.at(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    dp.at(0).at(0) = true;
    for (int i = 1; i <= n; i++)
        dp.at(0).at(i) = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (j < a.at(i))
            {
                if (dp.at(i - 1).at(j) == true)
                    dp.at(i).at(j) = true;
                else
                    dp.at(i).at(j) = false;
            }
            if (j >= a.at(i))
            {
                if (dp.at(i - 1).at(j) == true || dp.at(i - 1).at(j - a.at(i)) == true)
                    dp.at(i).at(j) = true;
                else
                    dp.at(i).at(j) = false;
            }
        }
    }

    if (dp.at(n).at(s) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
