//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
    int m, n, i, j, sum = 0;
    double start_time, end_time;
    int **a, **b, **c;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &m, &n);

    a = (int **) malloc(m * sizeof(int *));
    b = (int **) malloc(m * sizeof(int *));
    c = (int **) malloc(m * sizeof(int *));

    for (i = 0; i < m; i++) {
        a[i] = (int *) malloc(n * sizeof(int));
        b[i] = (int *) malloc(n * sizeof(int));
        c[i] = (int *) malloc(n * sizeof(int));
    }

    srand(time(NULL));

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    start_time = clock();
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
            sum += c[i][j];
        }
    }
    end_time = clock();

    printf("The sum of the elements in the resultant matrix is: %d\n", sum);
    printf("Time taken by the program to execute is: %.6f seconds\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}