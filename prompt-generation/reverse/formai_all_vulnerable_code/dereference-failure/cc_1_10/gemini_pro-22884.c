//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <assert.h>
#include <stdio.h>

typedef struct {
  int ring;
  struct toi *next;
} toi;

void push(toi **s, int ring) {
  toi *p = malloc(sizeof(*p));
  p->ring = ring;
  p->next = *s;
  *s = p;
}

int pop(toi **s) {
  toi *p = *s;
  int ring = p->ring;
  *s = p->next;
  free(p);
  return ring;
}

void print_stack(toi *s) {
  while (s) {
    printf("%d ", s->ring);
    s = s->next;
  }
  printf("\n");
}

void tower_of_hanoi(int n, toi **a, toi **b, toi **c) {
  if (n == 1) {
    push(c, pop(a));
    print_stack(*a);
    print_stack(*b);
    print_stack(*c);
    return;
  }
  tower_of_hanoi(n - 1, a, c, b);
  push(c, pop(a));
  tower_of_hanoi(n - 1, b, a, c);
}

int main() {
  toi *a = NULL, *b = NULL, *c = NULL;
  for (int i = 5; i >= 1; i--) push(&a, i);
  tower_of_hanoi(5, &a, &b, &c);
  assert(a == NULL && b == NULL && c != NULL);
  return 0;
}