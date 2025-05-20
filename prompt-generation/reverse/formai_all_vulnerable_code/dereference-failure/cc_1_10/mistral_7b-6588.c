//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100
#define EDGE_WEIGHT_MAX 10000

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

Edge edges[MAX_NODES * (MAX_NODES - 1) / 2];

int* parent;
int* rank;
int num_nodes;

void initialize_disjoint_set(int node) {
    parent[node] = node;
    rank[node] = 0;
}

int find_set(int node) {
    if (parent[node] != node) {
        parent[node] = find_set(parent[node]);
    }
    return parent[node];
}

void union_sets(int x, int y) {
    int root_x = find_set(x);
    int root_y = find_set(y);

    if (root_x == root_y) {
        return;
    }

    if (rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
    } else if (rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
        rank[root_x] += rank[root_y];
    } else {
        parent[root_y] = root_x;
        rank[root_x]++;
    }
}

bool compare_edges(const void* a, const void* b) {
    const Edge* edge_a = (const Edge*) a;
    const Edge* edge_b = (const Edge*) b;
    return edge_a->weight < edge_b->weight;
}

void add_edge(int src, int dest, int weight) {
    edges[num_nodes++] = (Edge){src, dest, weight};
}

void kruskal_mst() {
    qsort(edges, num_nodes, sizeof(Edge), compare_edges);

    int mst_edges = 0;

    for (int i = 0; i < num_nodes && mst_edges < num_nodes - 1; ++i) {
        int src = find_set(edges[i].src);
        int dest = find_set(edges[i].dest);

        if (src != dest) {
            printf("Edge %d-%d, weight %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            union_sets(src, dest);
            mst_edges++;
        }
    }
}

int main() {
    num_nodes = 5;

    initialize_disjoint_set(0);
    initialize_disjoint_set(1);
    initialize_disjoint_set(2);
    initialize_disjoint_set(3);
    initialize_disjoint_set(4);

    add_edge(0, 1, 4);
    add_edge(0, 2, 2);
    add_edge(1, 2, 5);
    add_edge(1, 3, 3);
    add_edge(2, 3, 1);
    add_edge(2, 4, 6);
    add_edge(3, 4, 7);

    kruskal_mst();

    return 0;
}