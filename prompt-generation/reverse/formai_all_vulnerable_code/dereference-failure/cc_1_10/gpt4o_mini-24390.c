//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_VERTICES 10

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
    pthread_mutex_t locks[MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        pthread_mutex_init(&graph->locks[i], NULL);
    }
    return graph;
}

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\nVertex %d: ", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
    }
    printf("\n");
}

void* visitVertex(void* arg) {
    int vertex = *((int*)arg);
    printf("Visiting vertex %d\n", vertex);
    return NULL;
}

void traverseGraph(Graph* graph, int startVertex) {
    pthread_t threads[MAX_VERTICES];
    int vertexIds[MAX_VERTICES];
    
    for (int i = 0; i < graph->numVertices; i++) {
        vertexIds[i] = i; // Initialize the vertex ids for each thread
        pthread_mutex_lock(&graph->locks[i]);
        pthread_create(&threads[i], NULL, visitVertex, &vertexIds[i]);
    }

    for (int i = 0; i < graph->numVertices; i++) {
        pthread_join(threads[i], NULL);
        pthread_mutex_unlock(&graph->locks[i]);
    }
}

int main() {
    Graph* graph = createGraph(5);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph adjacency list representation:");
    printGraph(graph);

    printf("\nTraversing the graph in a multi-threaded manner...\n");
    traverseGraph(graph, 0);
    
    // Clean up memory
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
        pthread_mutex_destroy(&graph->locks[i]);
    }
    free(graph);
    
    return 0;
}