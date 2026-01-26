#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;

    while (n > 0)
    {
        int rem = n % 2;
        s.push_back(rem + '0');
        n = n / 2;
    }

    for (int i = s.size(); i < 10; i++)
    {
        s.push_back('0');
    }

    reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}
