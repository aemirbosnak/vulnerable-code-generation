//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 100

int num_nodes, num_colors;
int **graph;
int *colors;

void init_graph() {
    graph = (int **)malloc(MAX_NODES * sizeof(int *));
    for (int i = 0; i < MAX_NODES; i++) {
        graph[i] = (int *)malloc(MAX_NODES * sizeof(int));
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }
}

void free_graph() {
    for (int i = 0; i < MAX_NODES; i++) {
        free(graph[i]);
    }
    free(graph);
}

void init_colors() {
    colors = (int *)malloc(MAX_COLORS * sizeof(int));
    for (int i = 0; i < MAX_COLORS; i++) {
        colors[i] = -1;
    }
}

void free_colors() {
    free(colors);
}

int is_valid_color(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i]!= 0 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void color_node(int node, int color) {
    colors[node] = color;
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i]!= 0 && colors[i] == -1) {
            colors[i] = color;
        }
    }
}

void print_graph(int **graph, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (graph[i][j]!= 0) {
                printf("%d ", graph[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void print_colors(int *colors, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    init_graph();
    init_colors();

    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            graph[i][j] = rand() % 2;
            graph[j][i] = rand() % 2;
        }
    }

    printf("Graph:\n");
    print_graph(graph, num_nodes);

    printf("Colors:\n");
    print_colors(colors, num_nodes);

    int k = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (colors[i] == -1) {
            color_node(i, k);
            k++;
        }
    }

    printf("Colored graph:\n");
    print_graph(graph, num_nodes);

    free_graph();
    free_colors();

    return 0;
}