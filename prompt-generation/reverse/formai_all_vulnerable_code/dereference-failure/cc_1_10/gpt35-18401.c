//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define NODES 5  // Number of nodes in the Graph
#define COLORS 3 // Number of colors to be assigned to the Graph

int graph[NODES][NODES] = { // Sample Graph matrix
    {0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 0}
};

int colorResult[NODES]; // Array to store the result color of each node
bool availableColors[COLORS]; // Array to check which colors are available
pthread_mutex_t mutex; // Mutex for thread synchronization

// Function to check if the selected color is safe for the current node
bool isSafe(int node, int color) {
    for(int i = 0; i < NODES; i++) {
        if(graph[node][i] && colorResult[i] == color)
            return false;
    }
    return true;
}

// Recursive function to assign color to each node
void* colorNodes(void *vargp) {
    int *node = (int *)vargp;
    for(int c = 0; c < COLORS; c++) {
        pthread_mutex_lock(&mutex);
        if(isSafe(*node, c) && !availableColors[c]) {
            colorResult[*node] = c;
            availableColors[c] = true;
            pthread_mutex_unlock(&mutex);
            if(*node + 1 < NODES) {
                int nextNode = *node + 1;
                colorNodes(&nextNode);
            }
            pthread_exit(NULL);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Main function
int main() {
    printf("Graph Coloring Problem using asynchronous programming\n\n");
    pthread_t tid[NODES];
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < COLORS; i++)
        availableColors[i] = false;
    for(int i = 0; i < NODES; i++) {
        int *node = malloc(sizeof(*node));
        *node = i;
        pthread_create(&tid[i], NULL, colorNodes, node);
    }
    for(int i = 0; i < NODES; i++)
        pthread_join(tid[i], NULL);
    printf("Color assigned to each node:\n\n");
    for(int i = 0; i < NODES; i++)
        printf("Node %d: Color %d\n", i+1, colorResult[i]+1);
    return 0;
}