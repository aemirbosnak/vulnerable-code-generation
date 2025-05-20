//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *email;
  struct node *next;
} node;

typedef struct list {
  node *head;
  node *tail;
} list;

list *create_list() {
  list *l = malloc(sizeof(list));
  l->head = NULL;
  l->tail = NULL;
  return l;
}

void add_email(list *l, char *email) {
  node *n = malloc(sizeof(node));
  n->email = strdup(email);
  n->next = NULL;
  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
  } else {
    l->tail->next = n;
    l->tail = n;
  }
}

void print_list(list *l) {
  node *n = l->head;
  while (n != NULL) {
    printf("%s\n", n->email);
    n = n->next;
  }
}

int main() {
  list *l = create_list();
  add_email(l, "alice@example.com");
  add_email(l, "bob@example.com");
  add_email(l, "charlie@example.com");
  print_list(l);
  return 0;
}