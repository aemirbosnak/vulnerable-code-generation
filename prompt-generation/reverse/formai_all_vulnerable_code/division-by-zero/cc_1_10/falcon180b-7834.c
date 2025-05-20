//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 10

typedef struct {
    int node;
    int color;
} GraphNode;

GraphNode graph[MAX_NODES];
int num_nodes;
int num_colors;

void generate_graph(int num_nodes) {
    srand(time(0));
    int i;
    for (i = 0; i < num_nodes; i++) {
        graph[i].node = rand() % num_nodes;
        graph[i].color = rand() % num_colors;
    }
}

int is_valid_coloring(int node, int color) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (graph[i].node == node && graph[i].color == color)
            return 0;
        if (graph[i].color == color && graph[i].node == node)
            return 0;
    }
    return 1;
}

void print_graph() {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("%d %d\n", graph[i].node, graph[i].color);
    }
}

int main() {
    int i;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    generate_graph(num_nodes);
    print_graph();

    return 0;
}