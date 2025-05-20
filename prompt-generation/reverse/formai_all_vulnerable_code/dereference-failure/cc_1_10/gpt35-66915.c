//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 10

// Define the graph structure
struct Graph {
    int V; // number of vertices
    int E; // number of edges
    int** matrix; // adjacency matrix
};

// Function to create a new graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = vertices;
    graph->E = 0;

    // Allocate memory for the adjacency matrix
    graph->matrix = malloc(vertices * sizeof(int*));
    for(int i = 0; i < vertices; i++) {
        graph->matrix[i] = calloc(vertices, sizeof(int));
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int from, int to)
{
    graph->matrix[from][to] = 1;
    graph->matrix[to][from] = 1;
    graph->E++;
}

// Structure to store the information needed for each thread
struct ThreadInfo {
    int id;
    int* visited;
    struct Graph* graph;
};

// Function to be run by each thread
void* dfs(void* arg) {
    struct ThreadInfo* info = (struct ThreadInfo*) arg;

    // Get the id of the current thread and mark the starting vertex as visited
    int id = info->id;
    int* visited = info->visited;
    int v = id;
    visited[v] = 1;

    // Traverse the graph using DFS
    printf("Thread %d traversing the graph starting at vertex %d\n", id, v);

    for(int i = 0; i < info->graph->V; i++) {
        if(info->graph->matrix[v][i] == 1 && !visited[i]) {
            printf("Thread %d visiting vertex %d\n", id, i);
            struct ThreadInfo* childInfo = malloc(sizeof(struct ThreadInfo));
            childInfo->id = i;
            childInfo->visited = visited;
            childInfo->graph = info->graph;
            dfs(childInfo);
            free(childInfo);
        }
    }

    printf("Thread %d finished traversing the graph starting at vertex %d\n", id, v);
    pthread_exit(NULL);
}

int main()
{
    struct Graph* graph = createGraph(MAX_VERTICES);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 3, 8);
    addEdge(graph, 4, 9);

    pthread_t threads[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    // Create a thread for each vertex and start the traversal
    for(int i = 0; i < graph->V; i++) {
        struct ThreadInfo* info = malloc(sizeof(struct ThreadInfo));
        info->id = i;
        info->visited = visited;
        info->graph = graph;

        printf("Creating thread %d\n", i);
        pthread_create(&threads[i], NULL, dfs, (void*) info);
    }

    // Join the threads when they finish
    for(int i = 0; i < graph->V; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}