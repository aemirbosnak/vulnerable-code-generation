//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
  char *name;
  int value;
  struct _node *next;
} node;

typedef struct _circuit {
  char *name;
  node *inputs;
  node *outputs;
  int (*func)(node *);
} circuit;

int not(node *n) {
  return !n->value;
}

int and(node *n) {
  node *p = n;
  int result = 1;
  while (p != NULL) {
    result = result && p->value;
    p = p->next;
  }
  return result;
}

int or(node *n) {
  node *p = n;
  int result = 0;
  while (p != NULL) {
    result = result || p->value;
    p = p->next;
  }
  return result;
}

int xor(node *n) {
  node *p = n;
  int result = 0;
  while (p != NULL) {
    result = result ^ p->value;
    p = p->next;
  }
  return result;
}

int main() {
  node *n1 = malloc(sizeof(node));
  n1->name = "n1";
  n1->value = 0;
  n1->next = NULL;

  node *n2 = malloc(sizeof(node));
  n2->name = "n2";
  n2->value = 1;
  n2->next = NULL;

  node *n3 = malloc(sizeof(node));
  n3->name = "n3";
  n3->value = 0;
  n3->next = NULL;

  node *n4 = malloc(sizeof(node));
  n4->name = "n4";
  n4->value = 1;
  n4->next = NULL;

  circuit c1 = {"c1", n1, n2, not};
  circuit c2 = {"c2", n3, n4, and};
  circuit c3 = {"c3", c1.outputs, c2.outputs, or};

  printf("%s = %d\n", c3.name, c3.func(c3.inputs));

  return 0;
}