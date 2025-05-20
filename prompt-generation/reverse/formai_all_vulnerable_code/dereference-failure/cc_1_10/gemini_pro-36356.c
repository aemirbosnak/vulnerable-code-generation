//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int age;
} person;

typedef struct {
  char *name;
  int age;
  struct node *next;
} node;

typedef struct {
  int size;
  node *head;
} list;

list *create_list() {
  list *l = malloc(sizeof(list));
  l->size = 0;
  l->head = NULL;
  return l;
}

void add_to_list(list *l, char *name, int age) {
  node *n = malloc(sizeof(node));
  n->name = malloc(strlen(name) + 1);
  strcpy(n->name, name);
  n->age = age;
  n->next = l->head;
  l->head = n;
  l->size++;
}

void print_list(list *l) {
  node *n = l->head;
  while (n != NULL) {
    printf("%s %d\n", n->name, n->age);
    n = n->next;
  }
}

void free_list(list *l) {
  node *n = l->head;
  while (n != NULL) {
    node *next = n->next;
    free(n->name);
    free(n);
    n = next;
  }
  free(l);
}

int main() {
  list *l = create_list();
  add_to_list(l, "John", 30);
  add_to_list(l, "Jane", 25);
  add_to_list(l, "Bob", 40);
  add_to_list(l, "Alice", 35);
  print_list(l);
  free_list(l);
  return 0;
}