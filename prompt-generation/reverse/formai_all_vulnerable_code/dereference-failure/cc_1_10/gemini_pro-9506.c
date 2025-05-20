//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dream {
  char *name;
  int cost;
  struct dream *next;
};

struct budget {
  int income;
  int expenses;
  struct dream *dreams;
};

struct budget *new_budget(int income, int expenses) {
  struct budget *b = malloc(sizeof(struct budget));
  b->income = income;
  b->expenses = expenses;
  b->dreams = NULL;
  return b;
}

struct dream *new_dream(char *name, int cost) {
  struct dream *d = malloc(sizeof(struct dream));
  d->name = strdup(name);
  d->cost = cost;
  d->next = NULL;
  return d;
}

void add_dream(struct budget *b, struct dream *d) {
  if (!b->dreams) {
    b->dreams = d;
  } else {
    struct dream *p = b->dreams;
    while (p->next) {
      p = p->next;
    }
    p->next = d;
  }
}

void print_budget(struct budget *b) {
  printf("Income: %d\n", b->income);
  printf("Expenses: %d\n", b->expenses);
  printf("Dreams:\n");
  struct dream *d = b->dreams;
  while (d) {
    printf("%s: %d\n", d->name, d->cost);
    d = d->next;
  }
}

void free_budget(struct budget *b) {
  free(b);
}

void free_dream(struct dream *d) {
  free(d->name);
  free(d);
}

int main() {
  struct budget *b = new_budget(1000, 500);
  add_dream(b, new_dream("Flying car", 100000));
  add_dream(b, new_dream("Time machine", 1000000));
  print_budget(b);
  free_budget(b);
  return 0;
}