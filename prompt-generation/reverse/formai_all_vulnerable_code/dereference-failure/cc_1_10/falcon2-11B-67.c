//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define MAX_COLORS 5

typedef struct {
    int vertex;
    int color;
} Node;

typedef struct {
    int nodes[MAX_NODES];
    int colors[MAX_COLORS];
} Graph;

void print_graph(Graph* graph) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < MAX_NODES; i++) {
        printf("%d\t\t", i);
        for (int j = 0; j < MAX_COLORS; j++) {
            if (graph->colors[i] & (1 << j)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    Graph* graph = (Graph*) malloc(sizeof(Graph));

    graph->nodes[0] = 1;
    graph->nodes[1] = 2;
    graph->nodes[2] = 3;
    graph->nodes[3] = 4;
    graph->nodes[4] = 5;
    graph->nodes[5] = 6;
    graph->nodes[6] = 7;
    graph->nodes[7] = 8;
    graph->nodes[8] = 9;
    graph->nodes[9] = 10;

    for (int i = 0; i < MAX_NODES; i++) {
        graph->colors[i] = rand() % MAX_COLORS;
    }

    int num_colors = 0;
    while (num_colors < MAX_NODES) {
        int num_available_colors = MAX_COLORS;
        for (int i = 0; i < MAX_NODES; i++) {
            if (!(graph->colors[i] & (1 << (num_colors % MAX_COLORS)))) {
                graph->colors[i] |= (1 << (num_colors % MAX_COLORS));
                num_available_colors--;
            }
        }
        if (num_available_colors == 0) {
            num_colors++;
            printf("Romeo: ");
            print_graph(graph);
            printf("\nJuliet: ");
            print_graph(graph);
            printf("\n");
        }
    }

    free(graph);
    return 0;
}