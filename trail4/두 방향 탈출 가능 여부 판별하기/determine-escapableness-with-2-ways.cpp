#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 2; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    dfs(0, 0);

    if (visited[n - 1][m - 1]) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
