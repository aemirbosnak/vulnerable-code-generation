//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 7
#define MAX_ITERATIONS 1000

typedef struct {
    int id;
    int color;
} Node;

Node* create_nodes(int n) {
    Node* nodes = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].color = -1;
    }
    return nodes;
}

void print_solution(Node* nodes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:%d ", nodes[i].id, nodes[i].color);
    }
    printf("\n");
}

int is_valid(Node* nodes, int n, int node_id, int color) {
    for (int i = 0; i < n; i++) {
        if (nodes[i].id == node_id && nodes[i].color == color) {
            return 0;
        }
    }
    return 1;
}

void color_node(Node* nodes, int n, int node_id, int color) {
    nodes[node_id].color = color;
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_NODES + 1;
    Node* nodes = create_nodes(n);

    int max_iterations = rand() % MAX_ITERATIONS + 1;
    int iterations = 0;

    while (iterations < max_iterations) {
        int node_id = rand() % n;
        int color = rand() % MAX_COLORS;

        if (is_valid(nodes, n, node_id, color)) {
            color_node(nodes, n, node_id, color);
            iterations = 0;
        } else {
            iterations++;
        }

        if (iterations == max_iterations) {
            printf("No solution found.\n");
            return 1;
        }
    }

    print_solution(nodes, n);

    return 0;
}