//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define the data structure to represent a graph
typedef struct graph {
    // The number of vertices in the graph
    int num_vertices;
    // The number of edges in the graph
    int num_edges;
    // The adjacency matrix representing the graph
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} graph_t;

// Create a new graph
graph_t* create_graph() {
    // Allocate memory for the graph
    graph_t* graph = (graph_t*)malloc(sizeof(graph_t));
    if (graph == NULL) {
        return NULL;
    }
    
    // Initialize the graph's properties
    graph->num_vertices = 0;
    graph->num_edges = 0;
    memset(graph->adjacency_matrix, 0, sizeof(graph->adjacency_matrix));
    
    return graph;
}

// Destroy the graph
void destroy_graph(graph_t* graph) {
    // Free the memory allocated for the graph
    free(graph);
}

// Add a vertex to the graph
int add_vertex(graph_t* graph) {
    // Check if the graph is full
    if (graph->num_vertices == MAX_VERTICES) {
        return -1;
    }
    
    // Add the vertex to the graph
    graph->num_vertices++;
    
    return 0;
}

// Add an edge to the graph
int add_edge(graph_t* graph, int source, int destination) {
    // Check if the source and destination vertices are valid
    if (source >= graph->num_vertices || destination >= graph->num_vertices) {
        return -1;
    }
    
    // Add the edge to the adjacency matrix
    graph->adjacency_matrix[source][destination] = 1;
    
    // Increment the number of edges in the graph
    graph->num_edges++;
    
    return 0;
}

// Remove a vertex from the graph
int remove_vertex(graph_t* graph, int vertex) {
    // Check if the vertex is valid
    if (vertex >= graph->num_vertices) {
        return -1;
    }
    
    // Remove the vertex from the adjacency matrix
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->adjacency_matrix[i][vertex] = 0;
        graph->adjacency_matrix[vertex][i] = 0;
    }
    
    // Decrement the number of vertices in the graph
    graph->num_vertices--;
    
    return 0;
}

// Remove an edge from the graph
int remove_edge(graph_t* graph, int source, int destination) {
    // Check if the source and destination vertices are valid
    if (source >= graph->num_vertices || destination >= graph->num_vertices) {
        return -1;
    }
    
    // Remove the edge from the adjacency matrix
    graph->adjacency_matrix[source][destination] = 0;
    
    // Decrement the number of edges in the graph
    graph->num_edges--;
    
    return 0;
}

// Print the graph
void print_graph(graph_t* graph) {
    // Print the adjacency matrix
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

// Depth-first search
void dfs(graph_t* graph, int vertex, int visited[]) {
    // Mark the vertex as visited
    visited[vertex] = 1;
    
    // Print the vertex
    printf("%d ", vertex);
    
    // Recursively visit the vertex's neighbors
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

// Breadth-first search
void bfs(graph_t* graph, int vertex, int visited[]) {
    // Create a queue to store the vertices to be visited
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    // Mark the vertex as visited and enqueue it
    visited[vertex] = 1;
    queue[rear++] = vertex;
    
    // While the queue is not empty
    while (front != rear) {
        // Dequeue the front vertex from the queue
        vertex = queue[front++];
        
        // Print the vertex
        printf("%d ", vertex);
        
        // Enqueue the vertex's neighbors
        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adjacency_matrix[vertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// Main function
int main() {
    // Create a new graph
    graph_t* graph = create_graph();
    
    // Add vertices to the graph
    for (int i = 0; i < 10; i++) {
        add_vertex(graph);
    }
    
    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 5);
    add_edge(graph, 2, 6);
    add_edge(graph, 3, 7);
    add_edge(graph, 3, 8);
    add_edge(graph, 4, 9);
    
    // Print the graph
    print_graph(graph);
    
    // Perform depth-first search
    int visited[MAX_VERTICES];
    memset(visited, 0, sizeof(visited));
    dfs(graph, 0, visited);
    printf("\n");
    
    // Perform breadth-first search
    memset(visited, 0, sizeof(visited));
    bfs(graph, 0, visited);
    printf("\n");
    
    // Destroy the graph
    destroy_graph(graph);
    
    return 0;
}