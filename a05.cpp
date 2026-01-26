#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a = k - i - j;
            if (a >= 1 && a <= n)
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
