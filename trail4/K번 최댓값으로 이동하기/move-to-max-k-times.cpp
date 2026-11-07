#include <iostream>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r, c;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    r--;
    c--;

    for (int i = 0; i < k; ++i) {
        int x = grid[r][c];

        queue<pair<int, int>> q;
        bool visited[100][100] = {};

        q.push({r, c});
        visited[r][c] = true;

        int bestR = -1;
        int bestC = -1;

        while (!q.empty()) {
            auto [curR, curC] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nr = curR + dr[d];
                int nc = curC + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                    continue;
                }

                if (visited[nr][nc]) {
                    continue;
                }

                if (grid[nr][nc] >= x) {
                    continue;
                }

                visited[nr][nc] = true;
                q.push({nr, nc});

                if (bestR == -1 ||
                    grid[nr][nc] > grid[bestR][bestC] ||
                    (grid[nr][nc] == grid[bestR][bestC] && nr < bestR) ||
                    (grid[nr][nc] == grid[bestR][bestC] && nr == bestR && nc < bestC)) {
                        bestR = nr;
                        bestC = nc;
                }
            }
        }

        if (bestR == -1) {
            break;
        }

        r = bestR;
        c = bestC;
    }

    cout << r + 1 << " " << c + 1 << "\n";

    return 0;
}
