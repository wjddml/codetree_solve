#include <iostream>

using namespace std;

int R, C;
char grid[15][15];

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int res = 0;

    for (int r1 = 1; r1 < R - 2; ++r1) {
        for (int c1 = 1; c1 < C - 2; ++c1) {
                for (int r2 = r1 + 1; r2 < R - 1; ++r2) {
                    for (int c2 = c1 + 1; c2 < C - 1; ++c2) {
                        if (grid[0][0] != grid[r1][c1] && grid[r1][c1] != grid[r2][c2] && grid[r2][c2] != grid[R - 1][C - 1]) {
                            res++;
                        }
                    }
                }
        }
    }

    cout << res << "\n";

    return 0;
}