//Falcon-180B DATASET v1.0 Category: Data mining ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *)malloc(cols * sizeof(int));
    }
    m.rows = rows;
    m.cols = cols;
    return m;
}

void destroy_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        free(m.data[i]);
    }
    free(m.data);
}

void print_matrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

void fill_random(Matrix m) {
    srand(time(NULL));
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            m.data[i][j] = rand() % 100;
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid input.\n");
        return 1;
    }

    Matrix m = create_matrix(rows, cols);
    fill_random(m);
    printf("Random matrix:\n");
    print_matrix(m);

    destroy_matrix(m);

    return 0;
}