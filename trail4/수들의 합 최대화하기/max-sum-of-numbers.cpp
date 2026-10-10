#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[10][10];
bool visited[10];
int max_sum = 0;

void search(int row, int current_sum) {
    if (row == n) {
        max_sum = max(max_sum, current_sum);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (!visited[col]) {
            visited[col] = true;
            search(row + 1, current_sum + grid[row][col]);
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

    search(0, 0);

    cout << max_sum << "\n";

    return 0;
}
