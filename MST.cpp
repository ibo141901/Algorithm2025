#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int find_parent(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_parent(parent, parent[x]);
}

bool union_nodes(vector<int>& parent, int a, int b) {
    a = find_parent(parent, a);
    b = find_parent(parent, b);
    if (a == b) return false; 
    if (a < b) parent[b] = a;
    else parent[a] = b;
    return true;
}

int main() {
    int n; 
    cout << "���� ���� �Է�: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "���� ��� �Է� (����ġ, ���� ������ 0):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (adj[i][j] != 0) {
                edges.push_back({ i, j, adj[i][j] });
            }
        }
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
        });

    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;

    vector<vector<int>> mst(n, vector<int>(n, 0));

    int edge_count = 0;
    for (auto& e : edges) {
        if (union_nodes(parent, e.u, e.v)) {
            mst[e.u][e.v] = mst[e.v][e.u] = e.w;
            edge_count++;
            if (edge_count == n - 1) break; 
        }
    }

    cout << "\n����Ʈ���� ���� ��ĵ�:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mst[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
