//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person {
  char *name;
  char *number;
} person;

typedef struct _node {
  person *data;
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

void list_add(list *l, person *p) {
  node *new_node = malloc(sizeof(node));
  new_node->data = p;
  new_node->next = NULL;

  if (l->head == NULL) {
    l->head = new_node;
    l->tail = new_node;
  } else {
    l->tail->next = new_node;
    l->tail = new_node;
  }
}

void list_print(list *l) {
  node *current = l->head;

  while (current != NULL) {
    printf("%s: %s\n", current->data->name, current->data->number);
    current = current->next;
  }
}

int main() {
  list phone_book;
  list_init(&phone_book);

  person *alice = malloc(sizeof(person));
  alice->name = "Alice";
  alice->number = "123-456-7890";
  list_add(&phone_book, alice);

  person *bob = malloc(sizeof(person));
  bob->name = "Bob";
  bob->number = "987-654-3210";
  list_add(&phone_book, bob);

  person *carol = malloc(sizeof(person));
  carol->name = "Carol";
  carol->number = "012-345-6789";
  list_add(&phone_book, carol);

  list_print(&phone_book);

  return 0;
}