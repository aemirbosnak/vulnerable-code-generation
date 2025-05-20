//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 1000

struct node {
    int data;
    int rank;
    int parent;
    int child[MAX_NODE];
    int num_children;
};

int find_parent(struct node* nodes, int i) {
    if (nodes[i].parent == -1) {
        return -1;
    }
    return nodes[i].parent;
}

int find_child(struct node* nodes, int i) {
    int j = 0;
    while (j < nodes[i].num_children) {
        if (nodes[i].child[j] == -1) {
            return -1;
        }
        j++;
    }
    return nodes[i].child[j - 1];
}

void union_nodes(struct node* nodes, int i, int j) {
    int parent_i = find_parent(nodes, i);
    int parent_j = find_parent(nodes, j);

    if (parent_i!= parent_j) {
        if (nodes[parent_i].rank > nodes[parent_j].rank) {
            nodes[parent_j].parent = parent_i;
        } else {
            nodes[parent_i].parent = parent_j;
            if (nodes[parent_i].rank == nodes[parent_j].rank) {
                nodes[parent_j].rank++;
            }
        }
    }
}

int main() {
    int num_nodes;
    scanf("%d", &num_nodes);

    struct node* nodes = (struct node*)malloc(num_nodes * sizeof(struct node));
    memset(nodes, 0, num_nodes * sizeof(struct node));

    int i;
    for (i = 0; i < num_nodes; i++) {
        nodes[i].data = i;
        nodes[i].rank = 0;
        nodes[i].parent = -1;
        nodes[i].child[0] = -1;
        nodes[i].num_children = 0;
    }

    int num_edges;
    scanf("%d", &num_edges);

    int u, v;
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &u, &v);
        union_nodes(nodes, u, v);
    }

    int root = -1;
    for (i = 0; i < num_nodes; i++) {
        if (nodes[i].parent == -1) {
            root = i;
            break;
        }
    }

    printf("Root: %d\n", root);

    for (i = 0; i < num_nodes; i++) {
        printf("%d -> ", i);
        int j = find_parent(nodes, i);
        while (j!= -1) {
            printf("%d ", j);
            j = find_parent(nodes, j);
        }
        printf("\n");
    }

    free(nodes);
    return 0;
}