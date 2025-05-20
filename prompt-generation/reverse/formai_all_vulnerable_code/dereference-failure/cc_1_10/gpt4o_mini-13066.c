//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_NODES 10

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_NODES];
    pthread_mutex_t locks[MAX_NODES];
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

Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    pthread_mutex_lock(&graph->locks[src]);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    pthread_mutex_unlock(&graph->locks[src]);

    // For undirected graph, add an edge from dest to src
    newNode = createNode(src);
    pthread_mutex_lock(&graph->locks[dest]);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
    pthread_mutex_unlock(&graph->locks[dest]);
}

void* printGraph(void* arg) {
    Graph* graph = (Graph*) arg;
    
    for (int i = 0; i < graph->numVertices; i++) {
        pthread_mutex_lock(&graph->locks[i]);
        printf("Vertex %d:", i);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
        pthread_mutex_unlock(&graph->locks[i]);
    }
    return NULL;
}

void* addEdgesThread(void* arg) {
    Graph* graph = (Graph*) arg;

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 4, 8);
    addEdge(graph, 5, 9);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    Graph* graph = createGraph(MAX_NODES);

    // Create a thread to add edges
    pthread_create(&thread1, NULL, addEdgesThread, (void*) graph);
    
    // Create a thread to print graph
    pthread_create(&thread2, NULL, printGraph, (void*) graph);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Clean up
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp;
        while (graph->adjLists[i]) {
            temp = graph->adjLists[i];
            graph->adjLists[i] = graph->adjLists[i]->next;
            free(temp);
        }
        pthread_mutex_destroy(&graph->locks[i]);
    }
    free(graph);

    return 0;
}