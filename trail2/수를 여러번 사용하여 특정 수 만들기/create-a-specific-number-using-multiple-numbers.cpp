#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C;

int main() {
    cin >> A >> B >> C;

    int max_val = 0;

    for (int i = 0; i * A <= C; ++i) {
        for (int j = 0; i * A + j * B <= C; ++j) {
            int current_sum = i * A + j * B;
            max_val = max(max_val, current_sum);
        }
    }
    
    cout << max_val << "\n";

    return 0;
}