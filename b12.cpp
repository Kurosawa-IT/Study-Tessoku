#include <bits/stdc++.h>
using namespace std;

double func(double x)
{
    return x * x * x + x;
}

int main()
{

    int n;
    cin >> n;

    double left = 0, right = 100;

    for (int i = 0; i < 20; i++)
    {
        double mid = (left + right) / 2.0;
        double tmp = func(mid);
        if (tmp > 1.0 * n)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    cout << left << endl;
    return 0;
}
