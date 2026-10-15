#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];

bool visited[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    queue<pair<int, int>> q;

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];

        int start_x = r[i] - 1;
        int start_y = c[i] - 1;
        q.push({start_x, start_y});
        visited[start_x][start_y] = true;    
    }

    int reachable_count = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        reachable_count++;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[nx][ny] && grid[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << reachable_count << "\n";

    return 0;
}
