//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph data structure
typedef struct Graph {
    int num_vertices;
    bool adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Create a new graph
Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = false;
        }
    }
    return graph;
}

// Add an edge to the graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adj_matrix[vertex1][vertex2] = true;
    graph->adj_matrix[vertex2][vertex1] = true;
}

// Print the graph
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Check if the graph is colorable
bool is_colorable(Graph* graph) {
    int colors[graph->num_vertices];
    for (int i = 0; i < graph->num_vertices; i++) {
        colors[i] = -1;
    }
    
    // Try all possible colors for each vertex
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int color = 0; color < graph->num_vertices; color++) {
            
            // Check if the color is valid
            bool valid = true;
            for (int j = 0; j < graph->num_vertices; j++) {
                if (graph->adj_matrix[i][j] && colors[j] == color) {
                    valid = false;
                    break;
                }
            }
            
            // If the color is valid, assign it to the vertex
            if (valid) {
                colors[i] = color;
                break;
            }
        }
        
        // If no valid color was found, the graph is not colorable
        if (colors[i] == -1) {
            return false;
        }
    }
    
    // If all vertices were assigned a color, the graph is colorable
    return true;
}

// Main function
int main() {
    // Create a graph
    Graph* graph = create_graph(4);
    
    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    
    // Print the graph
    printf("Graph:\n");
    print_graph(graph);
    
    // Check if the graph is colorable
    bool colorable = is_colorable(graph);
    
    // Print the result
    if (colorable) {
        printf("The graph is colorable.\n");
    } else {
        printf("The graph is not colorable.\n");
    }
    
    return 0;
}