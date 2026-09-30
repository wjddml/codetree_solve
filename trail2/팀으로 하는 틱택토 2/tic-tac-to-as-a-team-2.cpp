#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string inp[3];
set<pair<char, char>> winning_teams;

void check_line(char a, char b, char c) {
    set<char> unique_chars = {a, b, c};

    if (unique_chars.size() == 2) {
        auto k = unique_chars.begin();
        char p = *k++;
        char q = *k;

        winning_teams.insert({min(p, q), max(p, q)});
    }
}

int main() {
    for (int i = 0; i < 3; i++) cin >> inp[i];

    for (int i = 0; i < 3; ++i) {
        check_line(inp[i][0], inp[i][1], inp[i][2]);
    }   

    for (int j = 0; j < 3; ++j) {
        check_line(inp[0][j], inp[1][j], inp[2][j]);
    }

    check_line(inp[0][0], inp[1][1], inp[2][2]);
    check_line(inp[0][2], inp[1][1], inp[2][0]);

    cout << winning_teams.size() << "\n";

    return 0;
}