#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, int target_num) {
    visited[x][y] = true;
    int size = 1;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && grid[nx][ny] == target_num) {
                size += dfs(nx, ny, target_num);
            }
        }
    }

    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int puyo_count = 0;
    int max_block_size = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) {
                int block_size = dfs(i, j, grid[i][j]);

                if (block_size >= 4) {
                    puyo_count++;
                }

                max_block_size = max(max_block_size, block_size);
            }
        }
    }

    cout << puyo_count << " " << max_block_size << "\n";

    return 0;
}
