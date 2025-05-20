//Gemma-7B DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, m;
    char **a, **b, **c;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);

    a = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        a[i] = (char *)malloc(m * sizeof(char));
    }

    b = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        b[i] = (char *)malloc(m * sizeof(char));
    }

    c = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        c[i] = (char *)malloc(m * sizeof(char));
    }

    // Shape shifting begins

    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j] ^ c[i][j];
        }
    }

    // Free memory

    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    for (i = 0; i < n; i++) {
        free(b[i]);
    }
    free(b);

    for (i = 0; i < n; i++) {
        free(c[i]);
    }
    free(c);

    return 0;
}