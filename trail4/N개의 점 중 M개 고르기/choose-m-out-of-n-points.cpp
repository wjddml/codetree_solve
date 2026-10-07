#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int x[20], y[20];
vector <int> selected;
int min_max_dist = INT_MAX;

int get_dist_sq(int i, int j) {
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];
    return dx * dx + dy * dy;
}

int calc_max_dist() {
    int max_d = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            max_d = max(max_d, get_dist_sq(selected[i], selected[j]));
        }
    }
    return max_d;
}

void find_min_dist(int idx, int count) {
    if (count == m) {
        min_max_dist = min(min_max_dist, calc_max_dist());
        return;
    }

    if (idx == n) return;

    selected.push_back(idx);
    find_min_dist(idx + 1, count + 1);
    selected.pop_back();
    find_min_dist(idx + 1, count);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    find_min_dist(0, 0);

    cout << min_max_dist << "\n";

    return 0;
}
