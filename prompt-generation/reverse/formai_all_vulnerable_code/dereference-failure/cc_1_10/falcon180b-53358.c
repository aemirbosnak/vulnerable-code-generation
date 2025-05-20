//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 //number of nodes
#define P 0.7 //probability of connection

int **adj_matrix; //adjacency matrix to store connections
int **visited; //visited matrix to keep track of visited nodes
int num_connected; //number of connected nodes

void init() {
    int i, j;
    srand(time(NULL));
    adj_matrix = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        adj_matrix[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    visited = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        visited[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
    num_connected = 0;
}

void percolate() {
    int i, j;
    for (i = 0; i < N; i++) {
        if (!visited[i][i] && rand() % 100 < P) {
            adj_matrix[i][i] = 1;
            visited[i][i] = 1;
            num_connected++;
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (adj_matrix[i][j] == 1 &&!visited[i][j]) {
                visited[i][j] = 1;
                num_connected++;
            }
        }
    }
}

void print_matrix() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (adj_matrix[i][j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    init();
    percolate();
    print_matrix();
    printf("Number of connected nodes: %d\n", num_connected);
    return 0;
}