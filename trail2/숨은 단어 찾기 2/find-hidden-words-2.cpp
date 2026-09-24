#include <iostream>
#include <string>

using namespace std;

int N, M;
string arr[50];

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

bool isRange(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int d = 0; d < 8; ++d) {
                int r1 = i, c1 = j;
                int r2 = i + dx[d], c2 = j + dy[d];
                int r3 = i + 2 * dx[d], c3 = j + 2 * dy[d];

                if (isRange(r1, c1) && isRange(r2, c2) && isRange(r3, c3)) {
                    if (arr[r1][c1] == 'L' && arr[r2][c2] == 'E' &&arr[r3][c3] == 'E') {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}