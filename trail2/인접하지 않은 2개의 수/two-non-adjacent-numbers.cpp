#include <iostream>
#include <algorithm>

using namespace std;

int n;
int numbers[100];
int max_sum = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 2; j < n; ++j) {
            int current_sum = numbers[i] + numbers[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    cout << max_sum << "\n";

    return 0;
}