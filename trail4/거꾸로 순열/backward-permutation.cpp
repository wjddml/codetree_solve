#include <iostream>
#include <vector>

using namespace std;

int n;
bool visited[9];
vector<int> answer;

void PrintAnswer() {
    for (int i = 0; i < (int)answer.size(); ++i) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

void Choose(int curr_num) {
    if (curr_num == 0) {
        PrintAnswer();
        return;
    }

    for (int i = n; i > 0; --i) {
        if (visited[i]) continue;

        visited[i] = true;
        answer.push_back(i);

        Choose(curr_num - 1);

        visited[i] = false;
        answer.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    Choose(n);

    return 0;
}
