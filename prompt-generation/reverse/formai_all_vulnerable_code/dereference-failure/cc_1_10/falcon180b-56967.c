//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int id;
    char name[50];
    int num_neighbors;
    int *neighbor_list;
} Node;

void add_edge(Node *node1, Node *node2) {
    node1->num_neighbors++;
    node1->neighbor_list = (int *) realloc(node1->neighbor_list, sizeof(int) * node1->num_neighbors);
    node1->neighbor_list[node1->num_neighbors - 1] = node2->id;

    node2->num_neighbors++;
    node2->neighbor_list = (int *) realloc(node2->neighbor_list, sizeof(int) * node2->num_neighbors);
    node2->neighbor_list[node2->num_neighbors - 1] = node1->id;
}

int main() {
    int num_nodes, i, j, k;
    scanf("%d", &num_nodes);

    Node *nodes = (Node *) malloc(sizeof(Node) * num_nodes);

    for (i = 0; i < num_nodes; i++) {
        scanf("%d %s", &nodes[i].id, nodes[i].name);
        nodes[i].num_neighbors = 0;
        nodes[i].neighbor_list = NULL;
    }

    int num_edges, u, v;
    scanf("%d", &num_edges);

    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &u, &v);
        add_edge(&nodes[u], &nodes[v]);
    }

    for (i = 0; i < num_nodes; i++) {
        printf("%d %s %d ", nodes[i].id, nodes[i].name, nodes[i].num_neighbors);
        for (j = 0; j < nodes[i].num_neighbors; j++) {
            printf("%d ", nodes[i].neighbor_list[j]);
        }
        printf("\n");
    }

    return 0;
}