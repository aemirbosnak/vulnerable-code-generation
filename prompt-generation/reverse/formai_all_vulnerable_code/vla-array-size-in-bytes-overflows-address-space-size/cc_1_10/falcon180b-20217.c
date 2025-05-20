//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 99999

typedef struct {
    int id;
    int parent;
    int distance;
} Node;

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes, num_edges;

void initialize(int n) {
    num_nodes = n;
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].parent = -1;
        nodes[i].distance = INF;
    }
}

int find_parent(int i) {
    if (nodes[i].parent == -1)
        return i;
    return find_parent(nodes[i].parent);
}

void union_nodes(int x, int y) {
    int root_x = find_parent(x);
    int root_y = find_parent(y);
    if (root_x!= root_y) {
        nodes[root_x].parent = root_y;
    }
}

void kruskal_mst(int e) {
    int i, j, u, v;
    Edge result[e];
    for (i = 0; i < e; i++) {
        result[i] = edges[i];
    }
    for (i = 0; i < e; i++) {
        u = find_parent(result[i].start);
        v = find_parent(result[i].end);
        if (u!= v) {
            union_nodes(u, v);
        }
    }
}

void print_mst(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", nodes[i].parent + 1);
    }
}

int main() {
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    initialize(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge) {u, v, w};
    }
    kruskal_mst(m);
    print_mst(n);
    return 0;
}