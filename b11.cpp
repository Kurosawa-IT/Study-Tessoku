#include <bits/stdc++.h>
using namespace std;

int serch(vector<int> vec, int x)
{

    int ans = lower_bound(vec.begin(), vec.end(), x) - vec.begin();

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;

        int ans = serch(a, x);

        cout << ans << endl;
    }

    return 0;
}
