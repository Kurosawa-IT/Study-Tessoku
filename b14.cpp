#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m = n / 2;
    vector<long long> left_sums, right_sums;

    for (int bit = 0; bit < (1 << m); bit++)
    {
        long long sum = 0;
        for (int i = 0; i < m; i++)
        {
            if (bit & (1 << i))
            {
                sum += a[i];
            }
        }
        left_sums.push_back(sum);
    }

    for (int bit = 0; bit < (1 << (n - m)); bit++)
    {
        long long sum = 0;
        for (int i = 0; i < (n - m); i++)
        {
            if (bit & (1 << i))
            {
                sum += a[m + i];
            }
        }
        right_sums.push_back(sum);
    }

    sort(right_sums.begin(), right_sums.end());

    for (long long x : left_sums)
    {
        long long need = k - x;
        bool is_exist = binary_search(right_sums.begin(), right_sums.end(), need);

        if (is_exist)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}