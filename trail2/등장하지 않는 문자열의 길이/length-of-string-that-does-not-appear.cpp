#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int N;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> str;

    for (int L = 1; L <= N; ++L) {
        unordered_set<string> seen;
        bool is_unique = true;

        for (int i = 0; i <= N - L; ++i) {
            string sub = str.substr(i, L);

            if (seen.count(sub)) {
                is_unique = false;
                break;
            }
            seen.insert(sub);
        }
        if (is_unique) {
            cout << L << "\n";
            break;
        }
    }

    return 0;
}