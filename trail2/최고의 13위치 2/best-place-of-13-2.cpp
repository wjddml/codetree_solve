#include <iostream>

using namespace std;

int N;
int arr[20][20];

bool is_overlapping(int r1, int c1, int r2, int c2) {
    if (r1 != r2) return false;
    return abs(c1 - c2) < 3;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> arr[i][j];

    int max_coins = 0;

    for (int r1 = 0; r1 < N; ++r1) {
        for (int c1 = 0; c1 < N - 2; ++c1) {
            for (int r2 = 0; r2 < N; ++r2) {
                for (int c2 = 0; c2 < N - 2; ++c2) {
                    if (is_overlapping(r1, c1, r2, c2)) continue;

                    int coins1 = arr[r1][c1] + arr[r1][c1 + 1] + arr[r1][c1 + 2];
                    int coins2 = arr[r2][c2] + arr[r2][c2 + 1] + arr[r2][c2 + 2];

                    max_coins = max(max_coins, coins1 + coins2);
                }
            }
        }
    }

    cout << max_coins << "\n";

    return 0;
}