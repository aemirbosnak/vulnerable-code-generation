//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000

typedef struct node {
    int id;
    int color;
} Node;

void print_graph(Node nodes[], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", nodes[i].id);
        if (nodes[i].color!= -1) {
            printf("%d ", nodes[i].color);
        }
        printf("\n");
    }
}

Node* create_graph(int num_nodes) {
    Node* nodes = (Node*)malloc(num_nodes * sizeof(Node));
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i + 1;
        nodes[i].color = -1;
    }
    return nodes;
}

void assign_colors(Node* nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].color == -1) {
            for (int j = 0; j < num_nodes; j++) {
                if (j!= i && (nodes[j].color == -1 || nodes[j].color == nodes[i].color)) {
                    nodes[i].color = (nodes[i].color + 1) % MAX_NODES;
                }
            }
        }
    }
}

int main() {
    int num_nodes = 7;
    Node* nodes = create_graph(num_nodes);
    printf("Graph before coloring: \n");
    print_graph(nodes, num_nodes);
    assign_colors(nodes, num_nodes);
    printf("\nGraph after coloring: \n");
    print_graph(nodes, num_nodes);
    free(nodes);
    return 0;
}