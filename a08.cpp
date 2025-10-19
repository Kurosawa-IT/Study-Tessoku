#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<int>> x(h + 1, vector<int>(w + 1)), y(h + 1, vector<int>(w + 1));

    for (int i = 0; i < h + 1; i++) {
        for (int j = 0; j < w + 1; j++) {
            x.at(i).at(j) = 0;
            y.at(i).at(j) = 0;
        }
    }

    for (int i = 1; i < h + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            cin >> x.at(i).at(j);
        }
    }

    int q;
    cin >> q;
    vector<int> a(q + 1), b(q + 1), c(q + 1), d(q + 1);

    for (int i = 1; i < q + 1; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
    }

    for (int i = 1; i < h + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            y.at(i).at(j) = y.at(i).at(j - 1) + x.at(i).at(j);
        }
    }

    for (int j = 1; j < w + 1; j++) {
        for (int i = 1; i < h + 1; i++) {
            y.at(i).at(j) = y.at(i - 1).at(j) + y.at(i).at(j);
        }
    }

    for (int i = 1; i < q + 1; i++) {
        cout << y.at(a.at(i) - 1).at(b.at(i) - 1) + y.at(c.at(i)).at(d.at(i)) - y.at(a.at(i) -1).at(d.at(i)) - y.at(c.at(i)).at(b.at(i) - 1) << endl;
    }
}
