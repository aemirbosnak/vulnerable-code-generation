//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct { int r, c; double *a; } matrix;

matrix matrix_make(int r, int c) {
    matrix m = {r, c, malloc(r * c * sizeof(double))};
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            m.a[i * c + j] = 0;
    return m;
}

void matrix_free(matrix m) { free(m.a); }

matrix matrix_add(matrix m1, matrix m2) {
    if (m1.r != m2.r || m1.c != m2.c) {
        fprintf(stderr, "matrix_add: dimensions must match\n");
        exit(1);
    }
    matrix m = matrix_make(m1.r, m1.c);
    for (int i = 0; i < m.r; i++)
        for (int j = 0; j < m.c; j++)
            m.a[i * m.c + j] = m1.a[i * m.c + j] + m2.a[i * m.c + j];
    return m;
}

matrix matrix_sub(matrix m1, matrix m2) {
    if (m1.r != m2.r || m1.c != m2.c) {
        fprintf(stderr, "matrix_sub: dimensions must match\n");
        exit(1);
    }
    matrix m = matrix_make(m1.r, m1.c);
    for (int i = 0; i < m.r; i++)
        for (int j = 0; j < m.c; j++)
            m.a[i * m.c + j] = m1.a[i * m.c + j] - m2.a[i * m.c + j];
    return m;
}

matrix matrix_mul(matrix m1, matrix m2) {
    if (m1.c != m2.r) {
        fprintf(stderr, "matrix_mul: inner dimensions must match\n");
        exit(1);
    }
    matrix m = matrix_make(m1.r, m2.c);
    for (int i = 0; i < m.r; i++)
        for (int j = 0; j < m.c; j++)
            for (int k = 0; k < m1.c; k++)
                m.a[i * m.c + j] += m1.a[i * m.c + k] * m2.a[k * m.c + j];
    return m;
}

matrix matrix_transpose(matrix m) {
    matrix m2 = matrix_make(m.c, m.r);
    for (int i = 0; i < m.r; i++)
        for (int j = 0; j < m.c; j++)
            m2.a[j * m2.c + i] = m.a[i * m.c + j];
    return m2;
}

matrix matrix_pow(matrix m, int n) {
    if (n == 0) {
        matrix m2 = matrix_make(m.r, m.c);
        for (int i = 0; i < m.r; i++)
            for (int j = 0; j < m.c; j++)
                m2.a[i * m2.c + j] = (i == j);
        return m2;
    }
    if (n == 1) return m;
    matrix m2 = matrix_pow(m, n / 2);
    m2 = matrix_mul(m2, m2);
    if (n % 2) m2 = matrix_mul(m2, m);
    return m2;
}

void matrix_print(matrix m) {
    for (int i = 0; i < m.r; i++) {
        for (int j = 0; j < m.c; j++)
            printf("%8.3f ", m.a[i * m.c + j]);
        printf("\n");
    }
}

int main() {
    matrix m1 = matrix_make(3, 4);
    matrix m2 = matrix_make(4, 3);
    for (int i = 0; i < m1.r; i++)
        for (int j = 0; j < m1.c; j++)
            m1.a[i * m1.c + j] = i + j;
    for (int i = 0; i < m2.r; i++)
        for (int j = 0; j < m2.c; j++)
            m2.a[i * m2.c + j] = 2 * i - j;
    printf("m1:\n");
    matrix_print(m1);
    printf("\nm2:\n");
    matrix_print(m2);
    matrix m3 = matrix_add(m1, m2);
    printf("\nm1 + m2:\n");
    matrix_print(m3);
    matrix_free(m3);
    m3 = matrix_sub(m1, m2);
    printf("\nm1 - m2:\n");
    matrix_print(m3);
    matrix_free(m3);
    m3 = matrix_mul(m1, m2);
    printf("\nm1 * m2:\n");
    matrix_print(m3);
    matrix_free(m3);
    m3 = matrix_transpose(m1);
    printf("\nm1^T:\n");
    matrix_print(m3);
    matrix_free(m3);
    m3 = matrix_pow(m1, 3);
    printf("\nm1^3:\n");
    matrix_print(m3);
    matrix_free(m3);
    matrix_free(m1);
    matrix_free(m2);
    return 0;
}