#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> a(100009);

bool check (long long x) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += x / a.at(i);
    if (sum >= k) return true;
    return false;
}

int main()
{

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    long long left = 1, right = 1000000000;

    while (left < right) {
        long long mid = (left + right) / 2;
        bool answer = check(mid);
        if (answer == false) left = mid + 1;
        if (answer == true) right = mid;
    }

    cout << left << endl;
    return 0;
}