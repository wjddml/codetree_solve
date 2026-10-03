#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> combination;

void findCombination(int curr, int cnt) {
    if (cnt == M)  {
        for (int i = 0; i < combination.size(); ++i) {
            cout << combination[i] << " ";
        }
        cout << "\n";
        return;
    }

    if (curr > N) return;

    combination.push_back(curr);
    findCombination(curr + 1, cnt + 1);
    combination.pop_back();
    findCombination(curr + 1, cnt);
}

int main() {
    cin >> N >> M;

    findCombination(1, 0);

    return 0;
}
