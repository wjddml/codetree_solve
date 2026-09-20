#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int a[1003];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_total_distance = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int current_distance_sum = 0;

        for (int j = 0; j < n; ++j) {
            int distance = (j - i + n) % n;
            current_distance_sum += a[j] * distance;
        }

        min_total_distance = min(min_total_distance, current_distance_sum);
    }

    cout << min_total_distance << "\n";

    return 0;
}