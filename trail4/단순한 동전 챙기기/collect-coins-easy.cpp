#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
char grid[20][20];

struct Point {
    int r, c;
};

struct Coin {
    int num;
    int r, c;

    bool operator<(const Coin& other) const {
        return num < other.num;
    }
};

int get_dist(Point a, Point b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    Point start, end;
    vector<Coin> coins;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];

            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'E') {
                end = {i, j};
            } else if (grid[i][j] >= '1' && grid[i][j] <= '9') {
                coins.push_back({grid[i][j] - '0', i, j});
            }
        }
    }

    sort(coins.begin(), coins.end());

    int coin_cnt = coins.size();

    if (coin_cnt < 3) {
        cout << -1 << "\n";
        return 0;
    }

    int min_dist = 1e9;

    for (int i = 0; i < coin_cnt; ++i) {
        for (int j = i + 1; j < coin_cnt; ++j) {
            for (int k = j + 1; k < coin_cnt; ++k) {
                Point c1 = {coins[i].r, coins[i].c};
                Point c2 = {coins[j].r, coins[j].c};
                Point c3 = {coins[k].r, coins[k].c};

                int total_dist = get_dist(start, c1) + get_dist(c1, c2) + get_dist(c2, c3) + get_dist(c3, end);
                min_dist = min(min_dist, total_dist);
            }
        }
    }

    if (min_dist == 1e9) {
        cout << -1 << "\n";
    } else {
        cout << min_dist << "\n";
    }

    return 0;
}
