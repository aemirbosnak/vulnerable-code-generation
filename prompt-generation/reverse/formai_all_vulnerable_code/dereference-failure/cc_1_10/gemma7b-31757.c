//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct Matrix {
  int rows;
  int cols;
  double **data;
} Matrix;

Matrix *createMatrix(int r, int c) {
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = r;
  m->cols = c;
  m->data = (double **)malloc(r * sizeof(double *) + c * sizeof(double));
  for (int i = 0; i < r; i++) {
    m->data[i] = (double *)malloc(c * sizeof(double));
  }
  return m;
}

void destroyMatrix(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    free(m->data[i]);
  }
  free(m->data);
  free(m);
}

Matrix *addMatrix(Matrix *a, Matrix *b) {
  if (a->rows != b->rows || a->cols != b->cols) {
    return NULL;
  }
  Matrix *c = createMatrix(a->rows, a->cols);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      double sum = 0.0;
      for (int k = 0; k < b->rows; k++) {
        for (int l = 0; l < b->cols; l++) {
          sum += a->data[i][j] * b->data[k][l];
        }
      }
      c->data[i][j] = sum;
    }
  }
  return c;
}

int main() {
  Matrix *a = createMatrix(2, 3);
  a->data[0][0] = 1.0;
  a->data[0][1] = 2.0;
  a->data[0][2] = 3.0;
  a->data[1][0] = 4.0;
  a->data[1][1] = 5.0;
  a->data[1][2] = 6.0;

  Matrix *b = createMatrix(2, 3);
  b->data[0][0] = 2.0;
  b->data[0][1] = 3.0;
  b->data[0][2] = 4.0;
  b->data[1][0] = 5.0;
  b->data[1][1] = 6.0;
  b->data[1][2] = 7.0;

  Matrix *c = addMatrix(a, b);

  for (int i = 0; i < c->rows; i++) {
    for (int j = 0; j < c->cols; j++) {
      printf("%f ", c->data[i][j]);
    }
    printf("\n");
  }

  destroyMatrix(a);
  destroyMatrix(b);
  destroyMatrix(c);

  return 0;
}