#include <iostream>
#include <algorithm>
using namespace std;

int n;
int graph[20][20];

void bfs(int start) {
    int visited[20] = {0};
    int q[20], f = 0, r = -1;
    visited[start] = 1;
    q[++r] = start;

    while (f <= r) {
        int u = q[f++];
        cout << u << " ";
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                q[++r] = v;
            }
        }
    }
}

void dfsUtil(int u, int visited[]) {
    visited[u] = 1;
    cout << u << " ";
    for (int v = 0; v < n; v++) {
        if (graph[u][v] && !visited[v])
            dfsUtil(v, visited);
    }
}

void dfs(int start) {
    int visited[20] = {0};
    dfsUtil(start, visited);
}

int findMin(int key[], int mst[]) {
    int mn = 1e9, idx = -1;
    for (int i = 0; i < n; i++)
        if (!mst[i] && key[i] < mn) {
            mn = key[i];
            idx = i;
        }
    return idx;
}

void prim() {
    int key[20], mst[20] = {0}, parent[20];
    for (int i = 0; i < n; i++) key[i] = 1e9;
    key[0] = 0;
    parent[0] = -1;

    for (int c = 0; c < n - 1; c++) {
        int u = findMin(key, mst);
        mst[u] = 1;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
}

class Edge {
public:
    int u, v, w;
};

int findSet(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = findSet(parent, parent[x]);
}

void unionSet(int parent[], int rank[], int a, int b) {
    a = findSet(parent, a);
    b = findSet(parent, b);
    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[b] < rank[a]) parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}

void kruskal() {
    Edge edges[200];
    int eCount = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j]) {
                edges[eCount].u = i;
                edges[eCount].v = j;
                edges[eCount].w = graph[i][j];
                eCount++;
            }

    sort(edges, edges + eCount, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    int parent[20], rank[20] = {0};
    for (int i = 0; i < n; i++) parent[i] = i;

    for (int i = 0; i < eCount; i++) {
        int a = findSet(parent, edges[i].u);
        int b = findSet(parent, edges[i].v);
        if (a != b) {
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            unionSet(parent, rank, a, b);
        }
    }
}

void dijkstra(int src) {
    int dist[20], used[20] = {0};
    for (int i = 0; i < n; i++) dist[i] = 1e9;
    dist[src] = 0;

    for (int c = 0; c < n; c++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        used[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    for (int i = 0; i < n; i++)
        cout << src << " -> " << i << " = " << dist[i] << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int start;
    cin >> start;

    bfs(start);
    cout << endl;

    dfs(start);
    cout << endl;

    prim();
    cout << endl;

    kruskal();
    cout << endl;

    dijkstra(start);
}

