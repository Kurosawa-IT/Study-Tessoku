#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> a, long k, long long x)
{
    long long sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += x / a[i];
    }
    if (sum >= k)
        return true;
    return false;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long left = 1, right = 1000000000;
    while (left < right)
    {
        long long mid = (left + right) / 2;
        bool ans = check(a, k, mid);
        if (ans == false)
            left = mid + 1;
        if (ans == true)
            right = mid;
    }

    cout << left << endl;

    return 0;
}
