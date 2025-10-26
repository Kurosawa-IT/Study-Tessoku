#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d.at(i);
    }

    vector<int> p(n * n), q(n * n);
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            p.at(A * n + B) = a.at(A) + b.at(B);
        }
    }
    for (int C = 0; C < n; C++) {
        for(int D = 0; D < n; D++) {
            q.at(C * n + D) = c.at(C) + d.at(D); 
        }
    }

    sort(q.begin(), q.end());

    bool ans = false;
    for (int i = 0; i < n * n; i++) {
        auto tmp = lower_bound(q.begin(), q.end(), k - p.at(i));
        if (tmp != q.end() && *tmp == k - p.at(i)) ans = true;
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
