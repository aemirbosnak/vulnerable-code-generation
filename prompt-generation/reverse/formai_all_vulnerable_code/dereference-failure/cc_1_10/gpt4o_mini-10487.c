//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct {
    int start;
    int end;
} Edge;

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int vertexCount;
    pthread_mutex_t lock;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertices;
    pthread_mutex_init(&graph->lock, NULL);
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph* graph, Edge edge) {
    pthread_mutex_lock(&graph->lock);
    graph->adjacencyMatrix[edge.start][edge.end] = 1;
    graph->adjacencyMatrix[edge.end][edge.start] = 1; // Undirected graph
    pthread_mutex_unlock(&graph->lock);
}

void* handleEdges(void* arg) {
    Edge* edge = (Edge*)arg;
    Graph* graph = createGraph(MAX_VERTICES);
    
    addEdge(graph, *edge);
    
    printf("Edge added: (%d - %d)\n", edge->start, edge->end);
    return NULL;
}

void displayGraph(Graph* graph) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < graph->vertexCount; i++) {
        for (int j = 0; j < graph->vertexCount; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    pthread_mutex_destroy(&graph->lock);
    free(graph);
}

int main() {
    pthread_t threads[MAX_EDGES];
    Edge edges[MAX_EDGES] = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4},
        {3, 5}, {4, 5}, {5, 6}, {2, 6}, {0, 3}
    };

    Graph* graph = createGraph(MAX_VERTICES);
    
    for (int i = 0; i < 10; i++) {
        if (pthread_create(&threads[i], NULL, handleEdges, (void*)&edges[i]) != 0) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    displayGraph(graph);
    freeGraph(graph);
    
    return 0;
}