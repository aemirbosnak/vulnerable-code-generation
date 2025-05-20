//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Fractal {
  int dimension;
  Node** nodes;
} Fractal;

Fractal* fractal_create(int dimension) {
  Fractal* fractal = malloc(sizeof(Fractal));
  fractal->dimension = dimension;
  fractal->nodes = NULL;

  return fractal;
}

void fractal_insert(Fractal* fractal, int data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  if (fractal->nodes == NULL) {
    fractal->nodes = &node;
  } else {
    Node* tail = fractal->nodes;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    tail->next = node;
  }
}

int fractal_search(Fractal* fractal, int data) {
  Node* node = fractal->nodes;

  while (node) {
    if (node->data == data) {
      return 1;
    }
    node = node->next;
  }

  return 0;
}

int main() {
  Fractal* fractal = fractal_create(3);
  fractal_insert(fractal, 1);
  fractal_insert(fractal, 2);
  fractal_insert(fractal, 3);

  if (fractal_search(fractal, 2)) {
    printf("Data found.\n");
  } else {
    printf("Data not found.\n");
  }

  return 0;
}