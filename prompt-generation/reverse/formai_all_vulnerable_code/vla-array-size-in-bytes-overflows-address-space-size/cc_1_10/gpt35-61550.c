//FormAI DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>

int main() {
    printf("\nWelcome to the wild world of C Graphs!\n\n");
    
    int n, m;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &m);
    
    int edges[m][2];
    printf("Enter the edges of the graph (vertex1 vertex2): ");
    for(int i=0; i<m; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    
    printf("\nYour graph has been created with %d vertices and %d edges:", n, m);
    printf("\nVertices: ");
    for(int i=1; i<=n; i++) {
        printf("%d ", i);
    }
    printf("\nEdges: ");
    for(int i=0; i<m; i++) {
        printf("(%d,%d) ", edges[i][0], edges[i][1]);
    }
    printf("\n");
    
    int matrix[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            matrix[i][j] = 0;
        }
    }
    
    for(int i=0; i<m; i++) {
        matrix[edges[i][0]-1][edges[i][1]-1] = 1;
        matrix[edges[i][1]-1][edges[i][0]-1] = 1;
    }
    
    printf("\nAdjacency matrix of the graph:\n");
    printf("  ");
    for(int i=1; i<=n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i=0; i<n; i++) {
        printf("%d ", i+1);
        for(int j=0; j<n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}