//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining some fun colors to make it exciting!
#define COLOR_RED   "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

// Our happy graph with smiling vertices!
typedef struct _Vertex {
    char name;
    int color;
} Vertex;

// The graph with all its colorful connections!
typedef struct _Graph {
    int num_vertices;
    Vertex *vertices;
    int **edges;
    int *colors;
} Graph;

// Helper function to create a new vertex with a smiley name
Vertex* createVertex(char name) {
    Vertex *vertex = malloc(sizeof(Vertex));
    vertex->name = name;
    vertex->color = -1; // Initially, all vertices are uncolored (represented by -1)
    return vertex;
}

// Helper function to create a new graph with n vertices
Graph* createGraph(int n) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = n;
    graph->vertices = malloc(n * sizeof(Vertex));
    graph->edges = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->vertices[i] = *createVertex('A' + i); // Creating vertices with names A, B, C, ...
        graph->edges[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph->edges[i][j] = 0; // Initially, there are no edges between any vertices
        }
    }
    graph->colors = malloc(n * sizeof(int)); // Array to store the colors of each vertex
    return graph;
}

// Helper function to add an edge between two vertices
void addEdge(Graph *graph, char vertex1, char vertex2) {
    int vertex1_index = vertex1 - 'A';
    int vertex2_index = vertex2 - 'A';
    graph->edges[vertex1_index][vertex2_index] = 1;
    graph->edges[vertex2_index][vertex1_index] = 1;
}

// Helper function to check if two vertices are adjacent
int areAdjacent(Graph *graph, char vertex1, char vertex2) {
    int vertex1_index = vertex1 - 'A';
    int vertex2_index = vertex2 - 'A';
    return graph->edges[vertex1_index][vertex2_index];
}

// Helper function to print the graph with colored vertices
void printGraph(Graph *graph) {
    printf("Our happy graph with smiling vertices:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf(" %c", graph->vertices[i].name);
    }
    printf("\n");
    
    // Printing the edges with colors!
    char colors[7][8] = {COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_RESET};
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->edges[i][j]) {
                printf(" %c%c%s ", colors[graph->colors[i]], graph->vertices[j].name, colors[7]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// The heart of our program - a greedy graph coloring algorithm!
int colorGraph(Graph *graph) {
    // Initialize all colors to -1 (uncolored)
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->colors[i] = -1;
    }
    
    int color = 0; // Start with color 0
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->colors[i] == -1) { // If vertex is uncolored
            graph->colors[i] = color; // Assign it the current color
            for (int j = i + 1; j < graph->num_vertices; j++) {
                if (areAdjacent(graph, graph->vertices[i].name, graph->vertices[j].name) && graph->colors[j] == -1) {
                    // If vertex j is adjacent to i and uncolored, skip the current color
                    color = (color + 1) % 7; // Move to the next color
                }
            }
        }
    }
    
    return 0;
}

int main() {
    // Creating our colorful graph!
    Graph *graph = createGraph(6);
    addEdge(graph, 'A', 'B');
    addEdge(graph, 'A', 'D');
    addEdge(graph, 'B', 'C');
    addEdge(graph, 'C', 'D');
    addEdge(graph, 'D', 'E');
    addEdge(graph, 'E', 'F');
    addEdge(graph, 'F', 'A');
    
    colorGraph(graph); // Coloring our happy graph!
    printGraph(graph); // Admiring our colorful masterpiece!
    
    return 0;
}