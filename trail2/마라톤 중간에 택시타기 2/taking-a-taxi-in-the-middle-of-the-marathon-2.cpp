#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int x[100];
int y[100];

int get_distance(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int total_dist = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_dist += get_distance(i, i + 1);
    }

    int min_dist = total_dist;

    for (int i = 1; i < n - 1; ++i) {
        int original_path = get_distance(i - 1, i) + get_distance(i, i + 1);
        int new_path = get_distance(i - 1, i + 1);
        int current_dist = total_dist - original_path + new_path;

        min_dist = min(current_dist, min_dist);
    }

    cout << min_dist << "\n";

    return 0;
}