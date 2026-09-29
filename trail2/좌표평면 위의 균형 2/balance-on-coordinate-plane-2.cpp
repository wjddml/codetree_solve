#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x[100], y[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = n;

    for (int line_x = 2; line_x <= 98; line_x += 2) {
        for (int line_y = 2; line_y <= 98; line_y += 2) {
            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;

            for (int i = 0; i < n; ++i) {
                if (x[i] > line_x && y[i] > line_y) q1++;
                else if (x[i] < line_x && y[i] > line_y) q2++;
                else if (x[i] < line_x && y[i] < line_y) q3++;
                else if (x[i] > line_x && y[i] < line_y) q4++;
            }

            int max_q = max({q1, q2, q3, q4});
            ans = min(ans, max_q);
        }
    }

    cout << ans << "\n";

    return 0;
}