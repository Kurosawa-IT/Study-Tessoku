#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n), c(n), d(n), sum_a_b(n * n), sum_c_d(n * n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum_a_b[i * n + j] = a[i] + b[j];
            sum_c_d[i * n + j] = c[i] + d[j];
        }
    }

    sort(sum_c_d.begin(), sum_c_d.end());

    for (int i = 0; i < n * n; i++)
    {
        bool ans = binary_search(sum_c_d.begin(), sum_c_d.end(), k - sum_a_b[i]);
        if (ans)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
