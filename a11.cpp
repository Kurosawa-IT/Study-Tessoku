#include <bits/stdc++.h>
using namespace std;

int serch(vector<int> vec, int x)
{
    sort(vec.begin(), vec.end());
    int pos = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
    if (pos <= vec.size() - 1 && vec[pos] == x)
        return pos;
    return -1;
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = serch(a, x);

    cout << ans + 1 << endl;

    return 0;
}
