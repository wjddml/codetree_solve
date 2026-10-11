#include <iostream>
#include <algorithm>

using namespace std;

int n;
int A[10][10];
bool visited[10];
int min_cost = 1e9;

void search(int curr, int cnt, int cost) {
    if (cost >= min_cost) return;

    if (cnt == n) {
        if (A[curr][0] != 0) {
            min_cost = min(min_cost, cost + A[curr][0]);
        }
        return;
    }

    for (int next = 0; next < n; ++next) {
        if (!visited[next] && A[curr][next] > 0) {
            visited[next] = true;
            search(next, cnt + 1, cost + A[curr][next]);
            visited[next] = false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    visited[0] = true;

    search(0, 1, 0);

    cout << min_cost << "\n";

    return 0;
}
