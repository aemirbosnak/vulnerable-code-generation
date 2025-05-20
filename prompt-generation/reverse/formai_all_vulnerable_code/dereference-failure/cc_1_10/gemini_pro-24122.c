//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char *name;
  char *email;
  struct node *next;
};

struct list {
  struct node *head;
  struct node *tail;
};

void init(struct list *l) {
  l->head = NULL;
  l->tail = NULL;
}

void add(struct list *l, char *name, char *email) {
  struct node *n = malloc(sizeof(struct node));
  n->name = strdup(name);
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

void print(struct list *l) {
  struct node *n = l->head;
  while (n != NULL) {
    printf("%s <%s>\n", n->name, n->email);
    n = n->next;
  }
}

void free_list(struct list *l) {
  struct node *n = l->head;
  while (n != NULL) {
    struct node *next = n->next;
    free(n->name);
    free(n->email);
    free(n);
    n = next;
  }
}

int main(int argc, char **argv) {
  struct list l;
  int i;

  init(&l);

  for (i = 1; i < argc; i += 2) {
    add(&l, argv[i], argv[i + 1]);
  }

  print(&l);

  free_list(&l);

  return 0;
}