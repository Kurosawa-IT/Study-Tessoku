#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int cnt = 0;

    while (n > 0)
    {
        int tmp = n % 10;
        n /= 10;
        ans += tmp * pow(2, cnt);
        cnt++;
    }

    cout << ans << endl;

    return 0;
}
