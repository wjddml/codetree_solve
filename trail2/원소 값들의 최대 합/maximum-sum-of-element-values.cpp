#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[101];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int max_sum = 0;

    for (int i = 1; i <= n; ++i) {
        int current_pos = i;
        int current_sum = 0;

        for (int step = 0; step < m; ++step) {
            int next_val = arr[current_pos];
            current_sum += next_val;
            current_pos = next_val;
        }

        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";

    return 0;
}