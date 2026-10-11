#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[10][10];
bool visited[10];
int max_min_val = 0;

void search(int row, int current_min) {
    if (current_min <= max_min_val) return;

    if (row == n) {
        max_min_val = max(max_min_val, current_min);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (!visited[col]) {
            visited[col] = true;
            int next_min = min(current_min, grid[row][col]);
            search(row + 1, next_min);
            visited[col] = false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    search(0, 1e9);

    cout << max_min_val << "\n";

    return 0;
}
