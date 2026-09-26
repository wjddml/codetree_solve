#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, S;
int arr[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int min_ans = 1e9; // 충분히 큰 값으로 초기화

    // 모든 (i, j) 쌍을 완전탐색
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int current_sum = sum - arr[i] - arr[j];
            min_ans = min(min_ans, abs(current_sum - S));
        }
    }

    cout << min_ans << "\n";

    return 0;
}