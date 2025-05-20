//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6
#define SHAPES_COUNT 7

typedef struct {
    int vertices[MAX_VERTICES];
    int num_vertices;
} Graph;

typedef struct {
    char shape[10];
    int color;
} Shape;

Shape shapes[SHAPES_COUNT] = {{"triangle", 0}, {"square", 1}, {"circle", 2}, {"diamond", 3}, {"pentagon", 4}, {"hexagon", 5}, {"octagon", 6}};

int graph_coloring(Graph *graph) {
    int i, j, current_color = MIN_COLOR;
    for (i = 0; i < graph->num_vertices; i++) {
        for (j = 0; j < SHAPES_COUNT; j++) {
            if (graph->vertices[i] == shapes[j].color) {
                shapes[j].color = current_color;
                current_color++;
                if (current_color > MAX_COLOR) {
                    return -1; // Graph cannot be colored with given number of colors
                }
                break;
            }
        }
        if (j == SHAPES_COUNT) {
            return -1; // Graph cannot be colored with given number of colors
        }
    }
    for (i = 0; i < SHAPES_COUNT; i++) {
        printf("Shape %s has color %d\n", shapes[i].shape, shapes[i].color);
    }
    return 1;
}

void read_graph_from_file(const char *filename, Graph *graph) {
    FILE *file = fopen(filename, "r");
    char line[100];
    int vertices_count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "vertex") != NULL) {
            vertices_count++;
            graph->vertices[graph->num_vertices++] = -1;
        } else {
            int vertex1, vertex2;
            sscanf(line, "%s %s", line, line + strlen(line) - strlen(line + strlen(line) - 1));
            sscanf(line, "%d %d", &vertex1, &vertex2);
            graph->vertices[vertex1] = vertex2;
            graph->vertices[vertex2] = vertex1;
        }
    }
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <graph.txt>\n", argv[0]);
        return 1;
    }

    Graph graph = {0};
    read_graph_from_file(argv[1], &graph);

    int result = graph_coloring(&graph);

    if (result == -1) {
        printf("Error: Graph cannot be colored with given number of colors.\n");
    }

    return 0;
}