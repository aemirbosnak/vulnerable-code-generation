//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSIZE 100

typedef struct matrix {
  int rows;
  int cols;
  int *data;
} matrix;

matrix *matrix_new(int rows, int cols) {
  matrix *m = malloc(sizeof(matrix));
  if (m == NULL) return NULL;
  m->rows = rows;
  m->cols = cols;
  m->data = malloc(rows * cols * sizeof(int));
  if (m->data == NULL) {
    free(m);
    return NULL;
  }
  memset(m->data, 0, rows * cols * sizeof(int));
  return m;
}

void matrix_free(matrix *m) {
  if (m == NULL) return;
  free(m->data);
  free(m);
}

matrix *matrix_copy(matrix *m) {
  if (m == NULL) return NULL;
  matrix *n = matrix_new(m->rows, m->cols);
  if (n == NULL) return NULL;
  memcpy(n->data, m->data, m->rows * m->cols * sizeof(int));
  return n;
}

matrix *matrix_transpose(matrix *m) {
  if (m == NULL) return NULL;
  matrix *n = matrix_new(m->cols, m->rows);
  if (n == NULL) return NULL;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      n->data[j * n->rows + i] = m->data[i * m->cols + j];
    }
  }
  return n;
}

matrix *matrix_add(matrix *m, matrix *n) {
  if (m == NULL || n == NULL) return NULL;
  if (m->rows != n->rows || m->cols != n->cols) return NULL;
  matrix *r = matrix_new(m->rows, m->cols);
  if (r == NULL) return NULL;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      r->data[i * r->cols + j] = m->data[i * m->cols + j] +
                                   n->data[i * n->cols + j];
    }
  }
  return r;
}

matrix *matrix_subtract(matrix *m, matrix *n) {
  if (m == NULL || n == NULL) return NULL;
  if (m->rows != n->rows || m->cols != n->cols) return NULL;
  matrix *r = matrix_new(m->rows, m->cols);
  if (r == NULL) return NULL;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      r->data[i * r->cols + j] = m->data[i * m->cols + j] -
                                   n->data[i * n->cols + j];
    }
  }
  return r;
}

matrix *matrix_multiply(matrix *m, matrix *n) {
  if (m == NULL || n == NULL) return NULL;
  if (m->cols != n->rows) return NULL;
  matrix *r = matrix_new(m->rows, n->cols);
  if (r == NULL) return NULL;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < n->cols; j++) {
      for (int k = 0; k < m->cols; k++) {
        r->data[i * r->cols + j] +=
            m->data[i * m->cols + k] * n->data[k * n->cols + j];
      }
    }
  }
  return r;
}

void matrix_print(matrix *m) {
  if (m == NULL) return;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      printf("%d ", m->data[i * m->cols + j]);
    }
    printf("\n");
  }
}

int main(void) {
  matrix *a = matrix_new(3, 3);
  matrix *b = matrix_new(3, 3);
  matrix *c;

  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      a->data[i * a->cols + j] = i + j;
    }
  }

  for (int i = 0; i < b->rows; i++) {
    for (int j = 0; j < b->cols; j++) {
      b->data[i * b->cols + j] = j - i;
    }
  }

  printf("Matrix A:\n");
  matrix_print(a);

  printf("Matrix B:\n");
  matrix_print(b);

  printf("Matrix A + B:\n");
  c = matrix_add(a, b);
  matrix_print(c);
  matrix_free(c);

  printf("Matrix A - B:\n");
  c = matrix_subtract(a, b);
  matrix_print(c);
  matrix_free(c);

  printf("Matrix A * B:\n");
  c = matrix_multiply(a, b);
  matrix_print(c);
  matrix_free(c);

  printf("Matrix A^T:\n");
  c = matrix_transpose(a);
  matrix_print(c);
  matrix_free(c);

  matrix_free(a);
  matrix_free(b);

  return 0;
}