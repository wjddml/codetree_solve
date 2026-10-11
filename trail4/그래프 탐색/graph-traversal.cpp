#include <iostream>
#include <vector>

using namespace std;

int n, m;
int from[10000], to[10000];

vector<int> graph[1001];
bool visited[1001];
int count = 0;

void dfs(int curr) {
    for (int next : graph[curr]) {
        if (!visited[next]) {
            visited[next] = true;
            count++;
            dfs(next);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    for (int i = 0; i < m; ++i) {
        int u = from[i];
        int v = to[i];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited[1] = true;
    dfs(1);

    cout << count << "\n";

    return 0;
}
