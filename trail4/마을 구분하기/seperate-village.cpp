#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];
bool visited[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    int people_count = 1;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                people_count += dfs(nx, ny);
            }
        }
    }

    return people_count;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> villages;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = true;
                int count = dfs(i, j);
                villages.push_back(count);
            }
        }
    }

    sort(villages.begin(), villages.end());

    cout << villages.size() << "\n";
    for (int count : villages) {
        cout << count << "\n";
    }

    return 0;
}
