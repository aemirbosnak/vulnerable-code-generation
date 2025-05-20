//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int vertex;
    bool color;
} Node;

typedef struct graph {
    int num_vertices;
    Node *vertices;
} Graph;

Graph create_graph(int num_vertices) {
    Graph graph;
    graph.num_vertices = num_vertices;
    graph.vertices = malloc(num_vertices * sizeof(Node));
    for (int i = 0; i < num_vertices; i++) {
        graph.vertices[i].vertex = i;
        graph.vertices[i].color = false;
    }
    return graph;
}

void print_graph(Graph graph) {
    for (int i = 0; i < graph.num_vertices; i++) {
        if (graph.vertices[i].color) {
            printf("( ");
        }
        printf("%d ", graph.vertices[i].vertex);
        if (i!= graph.num_vertices - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

bool is_valid_color(Graph graph, int color) {
    for (int i = 0; i < graph.num_vertices; i++) {
        if (graph.vertices[i].color == color) {
            return false;
        }
    }
    return true;
}

void assign_colors(Graph graph, int num_colors) {
    for (int color = 1; color <= num_colors; color++) {
        if (is_valid_color(graph, color)) {
            for (int i = 0; i < graph.num_vertices; i++) {
                graph.vertices[i].color = graph.vertices[i].color || (color & (1 << i));
            }
            printf("Colors: ");
            print_graph(graph);
            printf("\n");
            break;
        }
    }
}

int main() {
    int num_vertices = 8;
    Graph graph = create_graph(num_vertices);
    assign_colors(graph, 4);
    return 0;
}