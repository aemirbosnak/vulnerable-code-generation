//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(char *a, char *b) {
    int a_len = strlen(a), b_len = strlen(b);
    int **matrix = (int **)malloc((a_len + 1) * sizeof(int *));
    
    for (int i = 0; i <= a_len; i++) {
        matrix[i] = (int *)malloc((b_len + 1) * sizeof(int));
        matrix[i][0] = i;
    }

    for (int j = 0; j <= b_len; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= a_len; i++) {
        for (int j = 1; j <= b_len; j++) {
            int cost = (a[i - 1] != b[j - 1]);
            matrix[i][j] = min(matrix[i - 1][j] + 1, 
                               matrix[i][j - 1] + 1, 
                               matrix[i - 1][j - 1] + cost);
        }
    }

    int distance = matrix[a_len][b_len];
    
    for (int i = 0; i <= a_len; i++) {
        free(matrix[i]);
    }
    
    free(matrix);
    
    return distance;
}

int main() {
    char *a = "kitten";
    char *b = "sitting";
    int distance = levenshtein_distance(a, b);
    printf("Levenshtein distance between %s and %s: %d\n", a, b, distance);
    return 0;
}