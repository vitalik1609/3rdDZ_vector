#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector <int> v2;
    int n, m = 2, counter = 1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v2.push_back(x);
    }

    sort(v2.begin(), v2.end());

    for (int i = 1; i < n; i++) {
        if (v2[i - 1] != v2[i]) counter++;
    }

    vector<vector<int>> v1(m, vector<int>(counter, 0));

    v1[0][0] = v2[0];
    v1[1][0] = 1;
    int j = 0;

    for (int i = 1; i < n; i++) {
        if (v2[i - 1] == v2[i]) {
            v1[1][j]++;
        }
        else {
            ++j;
            v1[0][j] = v2[i];
            v1[1][j] = 1;
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < counter; j++) {
            cout << v1[i][j] << " ";
        } cout << endl;
    }


    return 0;;
}