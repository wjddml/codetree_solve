#include <iostream>

using namespace std;

int n;
int x[20], y[20];

bool is_covered(int line_id, int px, int py) {
    if (line_id <= 10) {
        return px == line_id;
    } else {
        return py == (line_id - 11);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    bool possible = false;

    for (int i = 0; i < 22; ++i) {
        for (int j = i; j < 22; ++j) {
            for (int k = j; k < 22; ++k) {
                bool all_covered = true;

                for (int p = 0; p < n; ++p) {
                    if (!is_covered(i, x[p], y[p]) && !is_covered(j, x[p], y[p]) && !is_covered(k, x[p], y[p])) {
                        all_covered = false;
                        break;
                    }
                }

                if (all_covered) {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }
        if (possible) break;
    }

    cout << (possible ? 1 : 0) << "\n";

    return 0;
}