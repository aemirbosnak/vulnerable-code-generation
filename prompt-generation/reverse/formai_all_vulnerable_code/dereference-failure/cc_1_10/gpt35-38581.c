//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure to represent a graph node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int num_vertices;
    struct Node** adj_list;
    int* color;
};

// Function to create a new graph node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
struct Graph* createGraph(int num_vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;

    graph->adj_list = (struct Node**) malloc(num_vertices * sizeof(struct Node*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }

    graph->color = (int*) malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        graph->color[i] = -1; // initialize all colors to -1
    }

    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj_list[src];
    graph->adj_list[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adj_list[dest];
    graph->adj_list[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);

        struct Node* temp = graph->adj_list[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Function to check if a given color is valid for a vertex
int isValidColor(struct Graph* graph, int vertex, int color) {
    struct Node* temp = graph->adj_list[vertex];

    while (temp) {
        if (graph->color[temp->vertex] == color) {
            return 0;
        }
        temp = temp->next;
    }

    return 1;
}

// Function to perform graph coloring recursively
int graphColoring(struct Graph* graph, int vertex, int num_colors) {
    if (vertex == graph->num_vertices) {
        return 1;
    }

    for (int i = 0; i < num_colors; i++) {
        if (isValidColor(graph, vertex, i)) {
            graph->color[vertex] = i;

            if (graphColoring(graph, vertex + 1, num_colors)) {
                return 1;
            }

            graph->color[vertex] = -1; // backtrack
        }
    }

    return 0;
}

int main() {
    // Create a graph with 10 vertices and 15 edges
    struct Graph* graph = createGraph(MAX_VERTICES);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 5);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 8);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 9);
    addEdge(graph, 9, 5);
    addEdge(graph, 9, 6);
    addEdge(graph, 9, 7);

    // Print the graph before coloring
    printf("Graph before coloring:\n");
    printGraph(graph);
    printf("\n");

    // Perform graph coloring with 4 colors
    if (graphColoring(graph, 0, 4)) {
        printf("Graph coloring successful:\n");

        // Print the colors of each vertex
        for (int i = 0; i < graph->num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, graph->color[i]);
        }
    } else {
        printf("Graph coloring failed.\n");
    }

    return 0;
}