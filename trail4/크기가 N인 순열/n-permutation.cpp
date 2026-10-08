#include <iostream>
#include <vector>

using namespace std;

int n;
bool visited[10];
vector<int> answer;

void PrintAnswer() {
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

void Choose(int curr_num) {
    if (curr_num == n + 1) {
        PrintAnswer();
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        answer.push_back(i);

        Choose(curr_num + 1);

        answer.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> n;

    Choose(1);

    return 0;
}
