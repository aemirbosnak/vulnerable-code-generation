//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 3 // maximum colors allowed

int main() {
    int n = 5; // default number of nodes in the graph
    int edges[5][5] = { // default edge matrix
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    printf("Graph Coloring Problem\n");
    printf("---------------------\n");

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    // dynamic allocation of edge matrix
    int **adj_matrix;
    adj_matrix = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj_matrix[i] = (int *) malloc(n * sizeof(int));
    }

    printf("Enter the edge matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    // graph coloring algorithm
    int color[n];
    color[0] = 0; // assign first node the first color

    for (int i = 1; i < n; i++) {
        color[i] = -1; // initialize all other nodes with no color assigned
    }

    for (int i = 1; i < n; i++) {
        int available_colors[MAX_COLORS] = {1}; // initialize all available colors as true

        for (int j = 0; j < n; j++) {
            if (adj_matrix[i][j] && color[j] != -1) {
                available_colors[color[j]] = 0;
            }
        }

        int k;
        for (k = 0; k < MAX_COLORS; k++) {
            if (available_colors[k]) {
                color[i] = k;
                break;
            }
        }

        if (k == MAX_COLORS) {
            printf("Unable to color the graph with %d colors\n", MAX_COLORS);
            return 0;
        }
    }

    printf("\nColoring of the graph:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d - Color %d\n", i, color[i]);
    }

    // deallocate memory
    for (int i = 0; i < n; i++) {
        free(adj_matrix[i]);
    }
    free(adj_matrix);

    return 0;
}