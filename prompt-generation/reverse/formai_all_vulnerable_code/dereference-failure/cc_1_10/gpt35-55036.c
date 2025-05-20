//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define N 5

int graph[N][N] = {0}; // Matrix representing the graph
int visited[N] = {0}; // Visited array to keep track of visited nodes

/* This function adds edges to the graph */
void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

/* This function prints the adjacency matrix representation of the graph */
void printGraph()
{
    printf("Adjacency matrix of the graph:\n\n");

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", graph[i][j]);
        }
        
        printf("\n");
    }
    
    printf("\n");
}

/* This function performs DFS traversal starting from a particular node */
void* DFS(void* arg)
{
    int start = *((int*)arg);
    visited[start] = 1;
    
    printf("Starting DFS from node %d\n", start);
    
    for(int i = 0; i < N; i++)
    {
        if(graph[start][i] == 1 && visited[i] == 0)
        {
            printf("%d -> %d\n", start, i);
            DFS(&i);
        }
    }
    
    pthread_exit(NULL);
}

int main()
{
    /* Add edges to the graph */
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    
    /* Print the adjacency matrix representation of the graph */
    printGraph();
    
    /* Create threads for each node */
    pthread_t threads[N];
    
    for(int i = 0; i < N; i++)
    {
        int* arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&threads[i], NULL, DFS, arg);
    }
    
    /* Wait for all threads to finish */
    for(int i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}