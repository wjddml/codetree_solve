#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    int answer = 0;
    int count = 0;
    
    for (int i = 0; i < A.size() - 1; ++i) {
        if (A[i] == '(' && A[i + 1] == '(') {
            count++;
        } else if (A[i] == ')' && A[i + 1] == ')') {
            answer += count;
        }
    }

    cout << answer << "\n";

    return 0;
}