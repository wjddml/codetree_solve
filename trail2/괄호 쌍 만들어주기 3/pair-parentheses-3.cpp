#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    int ans = 0;
    int count = 0;

    for (char c : A) {
        if (c == '(') {
            count++;
        } else {
            ans += count;
        }
    }

    cout << ans << "\n";

    return 0;
}