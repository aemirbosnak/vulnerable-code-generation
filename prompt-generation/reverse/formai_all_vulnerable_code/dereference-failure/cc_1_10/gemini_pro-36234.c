//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// An incomplete representation of a graph that demonstrates the basics of making graphs
struct graph {
    int num_nodes;
    int num_edges;
    int **adj_matrix;
};

// Demonstration of a function to make a graph
struct graph* make_graph(int num_nodes) {
    struct graph *graph = (struct graph*)malloc(sizeof(struct graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = 0;
    graph->adj_matrix = (int**)malloc(sizeof(int*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_matrix[i] = (int*)malloc(sizeof(int) * num_nodes);
        memset(graph->adj_matrix[i], 0, sizeof(int) * num_nodes);
    }
    return graph;
}

// Demonstration of a function to add an edge to a graph
void add_edge(struct graph *graph, int from, int to, int weight) {
    graph->adj_matrix[from][to] = weight;
    graph->num_edges++;
}

// Demonstration of a function to print a graph
void print_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Demonstration of a function to free the memory allocated for a graph
void free_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Demonstration of a function to find the degree of a node in a graph
int degree(struct graph *graph, int node) {
    int deg = 0;
    for (int i = 0; i < graph->num_nodes; i++) {
        deg += graph->adj_matrix[node][i];
    }
    return deg;
}

// Demonstration of a function to check if a graph is complete
int is_complete(struct graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            if (graph->adj_matrix[i][j] == 0 && i != j) {
                return 0;
            }
        }
    }
    return 1;
}

// Demonstration of a function to check if a graph is connected
int is_connected(struct graph *graph) {
    int visited[graph->num_nodes];
    memset(visited, 0, sizeof(int) * graph->num_nodes);
    int start = 0;
    visited[start] = 1;
    int count = 1;
    while (count < graph->num_nodes) {
        for (int i = 0; i < graph->num_nodes; i++) {
            if (graph->adj_matrix[start][i] != 0 && visited[i] == 0) {
                visited[i] = 1;
                count++;
                start = i;
                break;
            }
        }
    }
    for (int i = 0; i < graph->num_nodes; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }
    return 1;
}

// Demonstration of a function to find the shortest path between two nodes in a graph
int shortest_path(struct graph *graph, int from, int to) {
    int dist[graph->num_nodes];
    memset(dist, -1, sizeof(int) * graph->num_nodes);
    dist[from] = 0;
    int queue[graph->num_nodes];
    int front = 0;
    int rear = 0;
    queue[rear++] = from;
    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < graph->num_nodes; i++) {
            if (graph->adj_matrix[current][i] != 0 && dist[i] == -1) {
                dist[i] = dist[current] + 1;
                queue[rear++] = i;
            }
        }
    }
    return dist[to];
}

int main() {
    // Demonstration of creating a graph
    struct graph *graph = make_graph(5);

    // Demonstration of adding edges to a graph
    add_edge(graph, 0, 1, 1);
    add_edge(graph, 1, 2, 1);
    add_edge(graph, 2, 3, 1);
    add_edge(graph, 3, 4, 1);
    add_edge(graph, 4, 0, 1);

    // Demonstration of printing a graph
    print_graph(graph);

    // Demonstration of finding the degree of a node in a graph
    printf("The degree of node 0 is: %d\n", degree(graph, 0));

    // Demonstration of checking if a graph is complete
    if (is_complete(graph)) {
        printf("The graph is complete.\n");
    } else {
        printf("The graph is not complete.\n");
    }

    // Demonstration of checking if a graph is connected
    if (is_connected(graph)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    // Demonstration of finding the shortest path between two nodes in a graph
    printf("The shortest path between node 0 and node 4 is: %d\n", shortest_path(graph, 0, 4));

    // Demonstration of freeing the memory allocated for a graph
    free_graph(graph);

    return 0;
}