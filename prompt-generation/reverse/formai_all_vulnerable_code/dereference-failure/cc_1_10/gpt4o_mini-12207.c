//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct {
    int vertices[MAX_VERTICES];
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

// Function prototypes
Graph* createGraph();
void addVertex(Graph* g, int vertex);
void addEdge(Graph* g, int src, int dest);
void displayGraph(Graph* g);
void freeGraph(Graph* g);
void depthFirstSearch(Graph* g, int vertex, int* visited);
void breadthFirstSearch(Graph* g, int startVertex);
void findShortestPath(Graph* g, int startVertex, int endVertex);

int main() {
    Graph* g = createGraph();
    
    // Adding vertices
    for(int i = 0; i < 6; i++) {
        addVertex(g, i);
    }

    // Adding edges
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 5);
    addEdge(g, 3, 5);
    addEdge(g, 4, 5);

    // Display the graph
    displayGraph(g);

    // Perform Depth First Search
    printf("Depth First Search starting from vertex 0:\n");
    int visited[MAX_VERTICES] = {0};
    depthFirstSearch(g, 0, visited);
    printf("\n");

    // Perform Breadth First Search
    printf("Breadth First Search starting from vertex 0:\n");
    breadthFirstSearch(g, 0);
    printf("\n");
    
    // Find shortest path from vertex 0 to vertex 5
    printf("Finding shortest path from vertex 0 to vertex 5:\n");
    findShortestPath(g, 0, 5);

    // Clean up
    freeGraph(g);
    return 0;
}

Graph* createGraph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = 0;
    g->numEdges = 0;
    
    // Initialize adjacency matrix
    for(int i = 0; i < MAX_VERTICES; i++) {
        for(int j = 0; j < MAX_VERTICES; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
    return g;
}

void addVertex(Graph* g, int vertex) {
    if(g->numVertices < MAX_VERTICES) {
        g->vertices[g->numVertices++] = vertex;
    } else {
        printf("Error: Maximum number of vertices reached\n");
    }
}

void addEdge(Graph* g, int src, int dest) {
    if(src >= g->numVertices || dest >= g->numVertices) {
        printf("Error: Invalid vertex index\n");
        return;
    }
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // For undirected graph
    g->numEdges++;
}

void displayGraph(Graph* g) {
    printf("Graph adjacency matrix:\n");
    for(int i = 0; i < g->numVertices; i++) {
        for(int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph* g) {
    free(g);
}

void depthFirstSearch(Graph* g, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for(int i = 0; i < g->numVertices; i++) {
        if(g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearch(g, i, visited);
        }
    }
}

void breadthFirstSearch(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

void findShortestPath(Graph* g, int startVertex, int endVertex) {
    int queue[MAX_VERTICES], front = 0, rear = -1;
    int visited[MAX_VERTICES] = {0};
    int parent[MAX_VERTICES] = {-1};

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int currentVertex = queue[front++];
        
        if (currentVertex == endVertex) {
            break;
        }

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
                parent[i] = currentVertex;
            }
        }
    }

    // Trace the path from endVertex to startVertex
    if (parent[endVertex] != -1) {
        printf("Shortest path: ");
        int path[MAX_VERTICES], pathIndex = 0;
        for (int v = endVertex; v != -1; v = parent[v]) {
            path[pathIndex++] = v;
        }
        
        for (int i = pathIndex - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("No path found from vertex %d to vertex %d\n", startVertex, endVertex);
    }
}