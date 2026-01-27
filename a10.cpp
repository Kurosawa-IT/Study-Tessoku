#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++) {
        p[i] = max(p[i - 1], a[i]);
    }

    vector<int> q(n);
    q[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        q[i] = max(q[i + 1], a[i]);
    }

    int d;
    cin >> d;

    for (int i = 0; i < d; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int ans = 0;
        if (l > 0) ans = max(ans, p[l - 1]);
        if (r < n - 1) ans = max(ans, q[r + 1]);

        cout << ans << endl;
    }
 
    return 0;
}
