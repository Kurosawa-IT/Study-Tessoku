#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = a[i - 1] + prefix[i - 1];
    }
    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int win = prefix[r] - prefix[l - 1];
        int len = r - l + 1;

        if (2 * win > len)
        {
            cout << "win" << endl;
        }
        else if (2 * win == len)
        {
            cout << "draw" << endl;
        }
        else
        {
            cout << "lose" << endl;
        }
    }

    return 0;
}
