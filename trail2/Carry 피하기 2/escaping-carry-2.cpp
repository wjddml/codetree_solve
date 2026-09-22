#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[20];

bool isCarry(int a, int b, int c) {
    while (a > 0 || b > 0 || c > 0) {
        int sum = (a % 10) + (b % 10) + (c % 10);
        if (sum >= 10) {
            return true;
        }
        a /= 10;
        b /= 10;
        c /= 10;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_sum = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (!isCarry(arr[i], arr[j], arr[k])) {
                    int current_sum = arr[i] + arr[j] + arr[k];
                    max_sum = max(max_sum, current_sum);
                }
            }
        }
    }

    cout << max_sum << "\n";

    return 0;
}