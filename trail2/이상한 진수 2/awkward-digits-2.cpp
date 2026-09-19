#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    string a;
    cin >> a;

    int max_val = 0;
    int len = a.length();

    for (int i = 0; i < len; ++i) {
        a[i] = (a[i] == '0') ? '1' : '0';

        int current = 0;
        for (int j = 0; j < len; ++j) {
            current = current * 2 + (a[j] - '0');
        }

        max_val = max(max_val, current);

        a[i] = (a[i] == '0') ? '1' : '0';
    }

    cout << max_val << "\n";

    return 0;
}