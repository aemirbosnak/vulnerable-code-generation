//GEMINI-pro DATASET v1.0 Category: Educational ; Style: portable
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NDIMS 3
#define BSIZE 8192

typedef uint64_t real_t;

static real_t *buf;
static int *shape, *strides;

static void init_tensor(int ndims, int *shape) {
  int i, n;
  strides = malloc(sizeof(int) * ndims);
  n = 1;
  for (i = ndims - 1; i >= 0; i--) {
    strides[i] = n;
    n *= shape[i];
  }
  buf = malloc(sizeof(real_t) * n);
}

static void free_tensor() {
  free(strides);
  free(buf);
}

static real_t *get_elem(int ndims, int *idx) {
  int i, offset = 0;
  for (i = 0; i < ndims; i++) {
    offset += idx[i] * strides[i];
  }
  return &buf[offset];
}

static void print_tensor(int ndims, int *shape) {
  int i, j, k, n;
  for (i = 0; i < shape[0]; i++) {
    for (j = 0; j < shape[1]; j++) {
      for (k = 0; k < shape[2]; k++) {
        printf("%llu ", *get_elem(ndims, (int[]){i, j, k}));
      }
      printf("\n");
    }
    printf("\n");
  }
}

static void fill_tensor(int ndims, int *shape, real_t val) {
  int i, j, k, n;
  for (i = 0; i < shape[0]; i++) {
    for (j = 0; j < shape[1]; j++) {
      for (k = 0; k < shape[2]; k++) {
        *get_elem(ndims, (int[]){i, j, k}) = val;
      }
    }
  }
}

static void add_tensors(int ndims, int *shape1, int *shape2) {
  int i, j, k, n;
  for (i = 0; i < shape1[0]; i++) {
    for (j = 0; j < shape1[1]; j++) {
      for (k = 0; k < shape1[2]; k++) {
        *get_elem(ndims, (int[]){i, j, k}) +=
            *get_elem(ndims, (int[]){i, j, k});
      }
    }
  }
}

int main(int argc, char **argv) {
  int shape1[] = {BSIZE, BSIZE, BSIZE};
  int shape2[] = {BSIZE, BSIZE, BSIZE};
  init_tensor(NDIMS, shape1);
  fill_tensor(NDIMS, shape1, 1);
  init_tensor(NDIMS, shape2);
  fill_tensor(NDIMS, shape2, 2);
  add_tensors(NDIMS, shape1, shape2);
  print_tensor(NDIMS, shape1);
  free_tensor();
  free_tensor();
  return 0;
}