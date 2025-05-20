//Falcon-180B DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, m, sum = 0;
    int **matrix;
    char file_name[100];
    FILE *fp;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);
    matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Enter the name of the file to save the matrix: ");
    scanf("%s", file_name);
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fprintf(fp, "%d ", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Matrix saved to file.\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
    }
    printf("The sum of all elements in the matrix is: %d\n", sum);
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}