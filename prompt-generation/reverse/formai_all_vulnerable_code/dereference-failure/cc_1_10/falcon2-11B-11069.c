//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vertex {
    int id;
    int color;
    struct vertex* next;
} vertex;

typedef struct graph {
    int num_vertices;
    vertex* vertices;
    int* colors;
} graph;

void print_graph(graph* g) {
    printf("Graph with %d vertices:\n", g->num_vertices);
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d -> %d : %d\n", g->vertices[i].id, g->vertices[i].next->id, g->colors[i]);
    }
}

int main() {
    srand(time(NULL));

    int num_vertices = 10;
    graph* g = (graph*)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->vertices = (vertex*)malloc(num_vertices * sizeof(vertex));
    g->colors = (int*)malloc(num_vertices * sizeof(int));

    // Generate random graph
    for (int i = 0; i < num_vertices; i++) {
        g->vertices[i].id = i;
        g->vertices[i].next = NULL;
        g->colors[i] = rand() % 4;
    }

    // Assign colors to vertices
    int color = 0;
    for (int i = 0; i < num_vertices; i++) {
        vertex* curr = g->vertices[i].next;
        while (curr!= NULL) {
            if (curr->color == g->colors[i]) {
                printf("Graph is not properly colored!\n");
                print_graph(g);
                return 1;
            }
            curr = curr->next;
        }
        g->colors[i] = color++;
    }

    // Print properly colored graph
    print_graph(g);

    free(g->vertices);
    free(g->colors);
    free(g);

    return 0;
}