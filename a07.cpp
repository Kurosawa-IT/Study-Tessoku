#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, n;
    cin >> d >> n;

    vector<int> sum(d);
    for (int i = 0; i < d; i++) {
        sum.at(i) = 0;
    }

    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        for (int j = l - 1; j <= r - 1; j++) {
            sum.at(j)++;
        }
    }

    for (int i = 0; i < d; i++) {
        cout << sum.at(i) << endl;
    }
}
