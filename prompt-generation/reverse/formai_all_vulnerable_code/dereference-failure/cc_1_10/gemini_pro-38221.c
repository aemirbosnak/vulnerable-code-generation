//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A graph is represented as an adjacency list. Each node in the graph is represented by a
// structure of type 'Node'. Each node has a value and a pointer to the next node in the
// adjacency list.
struct Node {
    int value;
    struct Node *next;
};

// A graph is represented as an array of nodes. Each node in the array represents a vertex
// in the graph. The index of the node in the array is the value of the vertex.
struct Graph {
    int num_vertices;
    struct Node **nodes;
};

// Create a new graph with the given number of vertices.
struct Graph *create_graph(int num_vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->nodes = malloc(sizeof(struct Node *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->nodes[i] = NULL;
    }
    return graph;
}

// Add an edge to the graph between the two given vertices.
void add_edge(struct Graph *graph, int v1, int v2) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = v2;
    new_node->next = graph->nodes[v1];
    graph->nodes[v1] = new_node;
    new_node = malloc(sizeof(struct Node));
    new_node->value = v1;
    new_node->next = graph->nodes[v2];
    graph->nodes[v2] = new_node;
}

// Print the graph to the console.
void print_graph(struct Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        struct Node *curr = graph->nodes[i];
        while (curr != NULL) {
            printf("%d ", curr->value);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Color the graph using the greedy algorithm.
void color_graph(struct Graph *graph) {
    int *colors = malloc(sizeof(int) * graph->num_vertices);
    for (int i = 0; i < graph->num_vertices; i++) {
        colors[i] = -1;
    }
    int curr_color = 0;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (colors[i] == -1) {
            colors[i] = curr_color;
            struct Node *curr = graph->nodes[i];
            while (curr != NULL) {
                if (colors[curr->value] == -1) {
                    colors[curr->value] = curr_color;
                }
                curr = curr->next;
            }
            curr_color++;
        }
    }
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

// Free the memory allocated for the graph.
void free_graph(struct Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct Node *curr = graph->nodes[i];
        while (curr != NULL) {
            struct Node *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(graph->nodes);
    free(graph);
}

int main() {
    // Create a graph with 6 vertices.
    struct Graph *graph = create_graph(6);

    // Add edges to the graph.
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    add_edge(graph, 3, 5);
    add_edge(graph, 4, 5);

    // Print the graph to the console.
    printf("Graph:\n");
    print_graph(graph);

    // Color the graph using the greedy algorithm.
    printf("Greedy Coloring:\n");
    color_graph(graph);

    // Free the memory allocated for the graph.
    free_graph(graph);

    return 0;
}