#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, n;
    cin >> d >> n;

    vector<int> prefix(d + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        prefix[l]++;
        prefix[r + 1]--;
    }

    for (int i = 0; i < d; i++)
    {
        if (i > 0)
            prefix[i] += prefix[i - 1];
        cout << prefix[i] << endl;
    }

    return 0;
}
