//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int color;
    int degree;
} Node;

void initialize_graph(Node* graph, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        graph[i].color = -1;
        graph[i].degree = 0;
    }
}

void add_edge(Node* graph, int vertex1, int vertex2) {
    graph[vertex1].degree++;
    graph[vertex2].degree++;
}

int find_first_uncolored_vertex(Node* graph, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[i].color == -1) {
            return i;
        }
    }
    return -1;
}

void color_graph(Node* graph, int num_vertices) {
    Node* vertices = malloc(num_vertices * sizeof(Node));
    initialize_graph(vertices, num_vertices);

    int num_colors = num_vertices * 3;
    int* color_array = malloc(num_colors * sizeof(int));
    int* color_index = malloc(num_vertices * sizeof(int));

    for (int i = 0; i < num_vertices; i++) {
        int color = i % num_colors;
        vertices[i].color = color;
        color_array[color] = i;
        color_index[i] = color;
    }

    int num_edges = 0;
    int* edge_list = malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (i!= j && graph[i].degree > 0 && graph[j].degree > 0) {
                add_edge(vertices, i, j);
                num_edges++;
            }
        }
    }

    int num_uncolored_vertices = num_vertices;
    while (num_uncolored_vertices > 0) {
        int uncolored_vertex = find_first_uncolored_vertex(vertices, num_vertices);
        if (uncolored_vertex == -1) {
            break;
        }

        int color = 0;
        while (color < num_colors) {
            if (color_array[color]!= uncolored_vertex) {
                color_array[color] = uncolored_vertex;
                color_index[uncolored_vertex] = color;
                vertices[uncolored_vertex].color = color;
                num_uncolored_vertices--;
            }
            color++;
        }
    }

    printf("Graph coloring:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d (%d) ", vertices[i].color, vertices[i].degree);
    }
    printf("\n");

    free(vertices);
    free(color_array);
    free(color_index);
    free(edge_list);
}

int main() {
    int num_vertices = 6;
    Node* graph = malloc(num_vertices * sizeof(Node));
    for (int i = 0; i < num_vertices; i++) {
        graph[i].color = -1;
        graph[i].degree = 0;
    }
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 5);
    color_graph(graph, num_vertices);
    return 0;
}