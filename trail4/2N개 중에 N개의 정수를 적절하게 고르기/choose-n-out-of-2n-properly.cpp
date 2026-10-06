#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int num[20];
int total_sum = 0;
int min_diff = 1e9;

void find_min_diff(int idx, int cnt, int current_sum) {
    if (cnt == n) {
        int other_sum = total_sum - current_sum;
        int diff = abs(current_sum - other_sum);
        min_diff = min(min_diff, diff);
        return;
    }

    if (idx >= 2 * n) return;

    find_min_diff(idx + 1, cnt + 1, current_sum + num[idx]);
    find_min_diff(idx + 1, cnt, current_sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        total_sum += num[i];
    }

    find_min_diff(0, 0, 0);

    cout << min_diff << "\n";

    return 0;
}
