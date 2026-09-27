#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[100];

int abs_sum(const vector<int>& v) {
    int res = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        res += abs(v[i + 1] - v[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min_ans = 1e9;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<int> temp;

            for (int k = 0; k < n; ++k) {
                if (k == j) continue;
            
                int val = arr[k];
                if (k == i) val *= 2;

                temp.push_back(val);
            }

            int current_score = abs_sum(temp);
            min_ans = min(min_ans, current_score);
        }
    }
    
    cout << min_ans << "\n";

    return 0;
}