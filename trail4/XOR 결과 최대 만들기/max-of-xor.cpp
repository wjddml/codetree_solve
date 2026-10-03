#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int A[20];
int max_val = 0;

void select(int idx, int cnt, int current_xor) {
    if (cnt == m) {
        max_val = max(max_val, current_xor);
        return;
    }

    if (idx == n) return;

    select(idx + 1, cnt + 1, current_xor ^ A[idx]);
    select(idx + 1, cnt, current_xor);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    select(0, 0, 0);

    cout << max_val << "\n";

    return 0;
}