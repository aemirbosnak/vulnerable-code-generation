//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a graph node
typedef struct {
    int color;
    int neighbors[100];
} GraphNode;

// Function to print a graph node
void print_node(GraphNode *node) {
    printf("Color: %d\n", node->color);
    for (int i = 0; i < 100; i++) {
        printf("%d ", node->neighbors[i]);
    }
    printf("\n");
}

// Function to print a graph
void print_graph(GraphNode *graph, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        print_node(graph + i);
    }
}

// Function to color a graph
void color_graph(GraphNode *graph, int num_nodes, int num_colors) {
    int *color_count = (int *)malloc(sizeof(int) * num_nodes);
    int *prev_color = (int *)malloc(sizeof(int) * num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        color_count[i] = 0;
        prev_color[i] = -1;
    }

    for (int i = 0; i < num_nodes; i++) {
        int min_color = -1;
        int min_color_node = -1;

        for (int j = 0; j < num_nodes; j++) {
            if (color_count[j] < min_color && prev_color[j]!= graph[i].color) {
                min_color = color_count[j];
                min_color_node = j;
            }
        }

        color_count[min_color_node]++;
        prev_color[min_color_node] = graph[i].color;
    }

    for (int i = 0; i < num_nodes; i++) {
        int color = -1;

        for (int j = 0; j < num_colors; j++) {
            if (color_count[j] > 0) {
                color = j;
                color_count[j]--;
                break;
            }
        }

        graph[i].color = color;
    }

    free(color_count);
    free(prev_color);
}

int main() {
    int num_nodes = 5;
    int num_colors = 3;

    GraphNode *graph = (GraphNode *)malloc(sizeof(GraphNode) * num_nodes);

    // Initialize graph
    for (int i = 0; i < num_nodes; i++) {
        graph[i].color = i;
        for (int j = 0; j < num_nodes; j++) {
            graph[i].neighbors[j] = -1;
        }
    }

    // Color graph
    color_graph(graph, num_nodes, num_colors);

    // Print graph
    printf("Graph:\n");
    print_graph(graph, num_nodes);

    return 0;
}