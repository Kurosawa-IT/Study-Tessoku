#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t >> n;

    vector<int> prefix(t + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        prefix[l]++;
        prefix[r]--;
    }

    for (int i = 0; i < t; i++)
    {
        if (i > 0)
        {
            prefix[i] += prefix[i - 1];
        }
        cout << prefix[i] << endl;
    }

    return 0;
}
