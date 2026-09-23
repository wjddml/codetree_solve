#include <iostream>

using namespace std;

int board[19][19];

int dr[4] = {0, 1, 1, -1};
int dc[4] = {1, 0, 1, 1};

bool checkFive(int r, int c, int color, int dir) {
    for (int i = 0; i < 5; ++i) {
        int next_r = r + dr[dir] * i;
        int next_c = c + dc[dir] * i;

        if (next_r < 0 || next_r >= 19 || next_c < 0 || next_c >= 19) {
            return false;
        }

        if (board[next_r][next_c] != color) {
            return false;
        }
    }

    return true;
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) cin >> board[i][j];

    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            if (board[i][j] == 0) continue;

            int currentColor = board[i][j];

            for (int d = 0; d < 4; ++d) {
                if (checkFive(i, j, currentColor, d)) {
                    cout << currentColor << "\n";

                    int center_r = i + dr[d] * 2;
                    int center_c = j + dc[d] * 2;
                    cout << center_r + 1 << " " << center_c + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << 0 << "\n";

    return 0;
}