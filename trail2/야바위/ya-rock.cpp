#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[100], b[100], c[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int max_score = 0;

    for (int start_pos = 1; start_pos <= 3; ++start_pos) {
        int current_pos = start_pos;
        int score = 0;

        for (int i = 0; i < N; ++i) {
            if (current_pos == a[i]) {
                current_pos = b[i];
            } else if (current_pos == b[i]) {
                current_pos = a[i];
            }

            if (current_pos == c[i]) {
                score++;
            }
        }

        max_score = max(score, max_score);
    }

    cout << max_score << "\n";

    return 0;
}