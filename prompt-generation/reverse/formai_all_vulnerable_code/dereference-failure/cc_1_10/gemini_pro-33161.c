//GEMINI-pro DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
  char *name;
  struct _node *next;
} node;

typedef struct _list {
  node *head;
  node *tail;
} list;

void list_init(list *l) {
  l->head = NULL;
  l->tail = NULL;
}

void list_add(list *l, char *name) {
  node *n = malloc(sizeof(node));
  n->name = strdup(name);
  n->next = NULL;
  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
  } else {
    l->tail->next = n;
    l->tail = n;
  }
}

void list_print(list *l) {
  node *n = l->head;
  while (n != NULL) {
    printf("%s\n", n->name);
    n = n->next;
  }
}

void list_free(list *l) {
  node *n = l->head;
  while (n != NULL) {
    node *next = n->next;
    free(n->name);
    free(n);
    n = next;
  }
}

int main(int argc, char **argv) {
  list l;
  list_init(&l);
  for (int i = 1; i < argc; i++) {
    list_add(&l, argv[i]);
  }
  list_print(&l);
  list_free(&l);
  return 0;
}