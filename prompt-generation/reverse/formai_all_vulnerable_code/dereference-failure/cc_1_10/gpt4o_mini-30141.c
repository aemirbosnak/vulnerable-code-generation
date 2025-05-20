//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    char vertexNames[MAX_VERTICES][20];
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
    return g;
}

// Function to add a vertex
void addVertex(Graph *g, const char *name) {
    if (g->numVertices < MAX_VERTICES) {
        strcpy(g->vertexNames[g->numVertices], name);
        g->numVertices++;
    } else {
        printf("Vertex limit reached!\n");
    }
}

// Function to add an edge
void addEdge(Graph *g, int start, int end) {
    if (start >= 0 && start < g->numVertices && end >= 0 && end < g->numVertices) {
        g->adjacencyMatrix[start][end] = 1; // Directed graph
        g->adjacencyMatrix[end][start] = 1; // If you want it to be undirected; comment this line for directed graph
    } else {
        printf("Invalid vertices!\n");
    }
}

// Function to display the graph
void displayGraph(Graph *g) {
    printf("Graph representation:\n");
    printf("%-15s", "Vertices");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%-15s", g->vertexNames[i]);
    }
    printf("\n");

    for (int i = 0; i < g->numVertices; i++) {
        printf("%-15s", g->vertexNames[i]);
        for (int j = 0; j < g->numVertices; j++) {
            printf("%-15d", g->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth First Search
void DFS(Graph *g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%s ", g->vertexNames[vertex]);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

// Function to initiate DFS
void startDFS(Graph *g) {
    int visited[MAX_VERTICES] = {0};

    printf("Depth First Search starting from vertex %s: ", g->vertexNames[0]);
    DFS(g, 0, visited);
    printf("\n");
}

// Function to perform Breadth First Search
void BFS(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("Breadth First Search starting from vertex %s: ", g->vertexNames[startVertex]);

    while (front != rear) {
        front++;
        int currentVertex = queue[front];
        printf("%s ", g->vertexNames[currentVertex]);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int vertices = 6;
    Graph *g = createGraph(vertices);

    addVertex(g, "A");
    addVertex(g, "B");
    addVertex(g, "C");
    addVertex(g, "D");
    addVertex(g, "E");
    addVertex(g, "F");

    addEdge(g, 0, 1); // A - B
    addEdge(g, 0, 2); // A - C
    addEdge(g, 1, 3); // B - D
    addEdge(g, 1, 4); // B - E
    addEdge(g, 2, 5); // C - F
    addEdge(g, 3, 5); // D - F

    displayGraph(g);
    
    startDFS(g);
    BFS(g, 0);

    // Clean up
    free(g);
    return 0;
}