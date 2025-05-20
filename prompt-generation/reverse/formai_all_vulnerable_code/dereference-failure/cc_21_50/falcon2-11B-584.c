//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, i, j, k;
    int **grid;
    int **visited;
    int *visited_row;
    int *visited_col;
    int *visited_diag;
    int *visited_anti_diag;
    srand(time(NULL));

    printf("Enter the dimensions of the grid (n x m): ");
    scanf("%d %d", &n, &m);

    grid = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    visited = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        visited[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }

    visited_row = (int *)malloc(m * sizeof(int));
    visited_col = (int *)malloc(m * sizeof(int));
    visited_diag = (int *)malloc(m * sizeof(int));
    visited_anti_diag = (int *)malloc(m * sizeof(int));

    printf("Percolation Simulation\n");
    for (k = 0; k < n; k++) {
        printf("Grid %d:\n", k + 1);
        for (i = 0; i < m; i++) {
            printf("%d ", grid[k][i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited[k][i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_row[i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_col[i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_diag[i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_anti_diag[i]);
        }
        printf("\n");
        printf("Initial state of the grid:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                printf("%d ", grid[k][i]);
            }
            printf("\n");
        }
        printf("Initial state of the visited grid:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                printf("%d ", visited[k][i]);
            }
            printf("\n");
        }
        printf("Initial state of the visited rows:\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_row[i]);
        }
        printf("\n");
        printf("Initial state of the visited columns:\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_col[i]);
        }
        printf("\n");
        printf("Initial state of the visited diagonals:\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_diag[i]);
        }
        printf("\n");
        printf("Initial state of the visited anti-diagonals:\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_anti_diag[i]);
        }
        printf("\n");

        for (i = 0; i < m; i++) {
            if (visited[k][i] == 0) {
                for (j = 0; j < m; j++) {
                    if (grid[k][i] == grid[k][j]) {
                        visited_row[i] = 1;
                        visited_col[i] = 1;
                        visited_diag[i] = 1;
                        visited_anti_diag[i] = 1;
                        if (visited[k][j] == 0) {
                            visited[k][j] = 1;
                            visited_row[j] = 1;
                            visited_col[j] = 1;
                            visited_diag[j] = 1;
                            visited_anti_diag[j] = 1;
                        }
                        for (k = 0; k < n; k++) {
                            if (k!= i && k!= j) {
                                if (grid[k][i] == grid[k][j]) {
                                    visited_diag[k] = 1;
                                    visited_anti_diag[k] = 1;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }

        printf("Grid %d:\n", k + 1);
        for (i = 0; i < m; i++) {
            printf("%d ", grid[k][i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited[k][i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_row[i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_col[i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_diag[i]);
        }
        printf("\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_anti_diag[i]);
        }
        printf("\n");
        printf("State of the grid after percolation:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                printf("%d ", grid[k][i]);
            }
            printf("\n");
        }
        printf("State of the visited grid after percolation:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                printf("%d ", visited[k][i]);
            }
            printf("\n");
        }
        printf("State of the visited rows after percolation:\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_row[i]);
        }
        printf("\n");
        printf("State of the visited columns after percolation:\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_col[i]);
        }
        printf("\n");
        printf("State of the visited diagonals after percolation:\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_diag[i]);
        }
        printf("\n");
        printf("State of the visited anti-diagonals after percolation:\n");
        for (i = 0; i < m; i++) {
            printf("%d ", visited_anti_diag[i]);
        }
        printf("\n");
        printf("End of percolation simulation\n");
    }

    return 0;
}