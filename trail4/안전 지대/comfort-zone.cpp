#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int grid[50][50];
bool visited[50][50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int K) {
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (!visited[nx][ny] && grid[nx][ny] > K) {
                dfs(nx, ny, K);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int max_height = 0;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            max_height = max(max_height, grid[i][j]);
        }
    }

    int best_K = 1;
    int max_zones = -1;

    for (int K = 1; K <= max_height; ++K) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                visited[i][j] = false;
            }
        }

        int current_zones = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] > K && !visited[i][j]) {
                    current_zones++;
                    dfs(i, j, K);
                }
            }
        }

        if (current_zones > max_zones) {
            max_zones = current_zones;
            best_K = K;
        }
    }

    cout << best_K << " " << max_zones << "\n";

    return 0;
}
