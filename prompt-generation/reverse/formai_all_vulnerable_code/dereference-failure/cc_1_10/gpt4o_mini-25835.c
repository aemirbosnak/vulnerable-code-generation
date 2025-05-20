//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function prototypes
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void displayGraph(struct Graph* graph);
void DFS(struct Graph* graph, int startVertex);
void BFS(struct Graph* graph, int startVertex);
void freeGraph(struct Graph* graph);
void dfsUtil(int vertex, bool visited[], struct Graph* graph);

// Main menu function
void menu(struct Graph* graph) {
    int choice, src, dest;
    do {
        printf("\nGraph Operations Menu:\n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. Depth-First Search (DFS)\n");
        printf("4. Breadth-First Search (BFS)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices: ");
                scanf("%d%d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                displayGraph(graph);
                break;
            case 3:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &src);
                printf("DFS starting from vertex %d:\n", src);
                DFS(graph, src);
                break;
            case 4:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &src);
                printf("BFS starting from vertex %d:\n", src);
                BFS(graph, src);
                break;
            case 5:
                freeGraph(graph);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 5);
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void displayGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dfsUtil(int vertex, bool visited[], struct Graph* graph) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList) {
        int connectedVertex = adjList->vertex;
        if (!visited[connectedVertex]) {
            dfsUtil(connectedVertex, visited, graph);
        }
        adjList = adjList->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    bool* visited = malloc(graph->numVertices * sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }
    dfsUtil(startVertex, visited, graph);
    free(visited);
}

void BFS(struct Graph* graph, int startVertex) {
    bool* visited = malloc(graph->numVertices * sizeof(bool));
    int* queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* adjList = graph->adjLists[currentVertex];
        while (adjList) {
            int connectedVertex = adjList->vertex;
            if (!visited[connectedVertex]) {
                visited[connectedVertex] = true;
                queue[rear++] = connectedVertex;
            }
            adjList = adjList->next;
        }
    }
    free(visited);
    free(queue);
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    int vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);
    menu(graph);
    return 0;
}