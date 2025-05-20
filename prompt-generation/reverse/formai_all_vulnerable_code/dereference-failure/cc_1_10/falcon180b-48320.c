//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 50
#define MAX_COLS 100
#define MAX_PATTERNS 10

int rows, cols, patterns;
int **patterns_matrix;

void generate_patterns() {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            patterns_matrix[i][j] = rand() % 2;
        }
    }
}

void print_patterns() {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", patterns_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter number of patterns: ");
    scanf("%d", &patterns);

    patterns_matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        patterns_matrix[i] = (int *) malloc(cols * sizeof(int));
    }

    generate_patterns();
    print_patterns();

    return 0;
}