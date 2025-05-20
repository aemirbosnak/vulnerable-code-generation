//FormAI DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#define MAXIMUM 200

int n;

// Graph representation using adjacency matrix
void adjacency_matrix(int graph[][MAXIMUM]) {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the graph: \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Graph representation using adjacency list
void adjacency_list(int graph[][MAXIMUM]) {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("Enter the number of adjacent vertices to vertex %d: ", i+1);
        int adj_vertices;
        scanf("%d", &adj_vertices);
        printf("Enter the adjacent vertices to vertex %d: ", i+1);
        for(int j=0; j<adj_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
        graph[i][adj_vertices] = -1; // -1 as sentinel value
    }
}

int main() {
    int graph[MAXIMUM][MAXIMUM];
    printf("Choose the type of graph representation: \n");
    printf("1. Adjacency Matrix.\n");
    printf("2. Adjacency List.\n");
    int opt;
    scanf("%d", &opt);
    switch(opt) {
        case 1:
            adjacency_matrix(graph);
            break;
        case 2:
            adjacency_list(graph);
            break;
        default:
            printf("Wrong choice, try again.\n");
            break;
    }
    printf("Input graph:\n");
    if(opt == 1) {
        // Print adjacency matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                printf("%d ", graph[i][j]);
            }
            printf("\n");
        }
    }
    else {
        // Print adjacency list
        for(int i=0; i<n; i++) {
            printf("%d -> ", i+1);
            int j=0;
            while(graph[i][j] != -1) {
                printf("%d -> ", graph[i][j]);
                j++;
            }
            printf("NULL\n");
        }
    }
    return 0;
}