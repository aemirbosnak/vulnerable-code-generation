//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate minimum of three numbers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Function to calculate Levenshtein Distance
int LD(char *s1, char *s2, int m, int n, int **LD_matrix) {
    int i, j, cost;

    // Initialize the first row and column
    for (i = 0; i <= m; i++) {
        LD_matrix[i][0] = i;
    }
    for (j = 0; j <= n; j++) {
        LD_matrix[0][j] = j;
    }

    // Fill the rest of the matrix
    for (j = 1; j <= n; j++) {
        for (i = 1; i <= m; i++) {
            if (s1[i - 1] == s2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            LD_matrix[i][j] = min(LD_matrix[i-1][j]+1, LD_matrix[i][j-1]+1, LD_matrix[i-1][j-1]+cost);
        }
    }

    return LD_matrix[m][n];
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";
    int m = strlen(s1);
    int n = strlen(s2);
    int **LD_matrix = (int**)malloc((m+1)*sizeof(int*));
    for (int i = 0; i <= m; i++) {
        LD_matrix[i] = (int*)malloc((n+1)*sizeof(int));
    }

    int result = LD(s1, s2, m, n, LD_matrix);

    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n", s1, s2, result);

    // Free memory
    for (int i = 0; i <= m; i++) {
        free(LD_matrix[i]);
    }
    free(LD_matrix);

    return 0;
}