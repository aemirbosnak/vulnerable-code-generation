//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 5 // size of the matrix
#define N 10 // size of the vector

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

typedef struct {
    int size;
    int *data;
} Vector;

Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int *)malloc(rows * cols * sizeof(int));
    return m;
}

Vector create_vector(int size) {
    Vector v;
    v.size = size;
    v.data = (int *)malloc(size * sizeof(int));
    return v;
}

void print_matrix(Matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

void print_vector(Vector v) {
    int i;
    for (i = 0; i < v.size; i++) {
        printf("%d ", v.data[i]);
    }
    printf("\n");
}

void add_matrix(Matrix m1, Matrix m2) {
    int i, j, k;
    for (i = 0; i < m1.rows; i++) {
        for (j = 0; j < m2.cols; j++) {
            for (k = 0; k < m2.rows; k++) {
                m1.data[i * m1.cols + j] += m2.data[k * m2.cols + j];
            }
        }
    }
}

void add_vector(Vector v1, Vector v2) {
    int i;
    for (i = 0; i < v1.size; i++) {
        v1.data[i] += v2.data[i];
    }
}

int main() {
    Matrix m1 = create_matrix(3, 4);
    Matrix m2 = create_matrix(4, 3);
    Vector v1 = create_vector(5);
    Vector v2 = create_vector(6);

    // fill matrices and vectors with random data
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1.data[i * 4 + j] = rand() % 10;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            m2.data[i * 3 + j] = rand() % 10;
        }
    }
    for (int i = 0; i < 5; i++) {
        v1.data[i] = rand() % 10;
    }
    for (int i = 0; i < 6; i++) {
        v2.data[i] = rand() % 10;
    }

    // print matrices and vectors
    print_matrix(m1);
    print_matrix(m2);
    print_vector(v1);
    print_vector(v2);

    // add matrices
    add_matrix(m1, m2);

    // add vectors
    add_vector(v1, v2);

    // print results
    print_matrix(m1);
    print_vector(v1);

    return 0;
}