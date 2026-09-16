#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int n;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int min = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += A[j] * abs(i - j);
        }
        if (sum < min) {
            min = sum;
        }
    }

    cout << min << "\n";

    return 0;
}