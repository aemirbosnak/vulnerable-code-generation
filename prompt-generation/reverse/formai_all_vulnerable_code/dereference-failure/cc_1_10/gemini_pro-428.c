//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *name;
  char *email;
  struct node *next;
} node;

typedef struct list {
  node *head;
  node *tail;
  int size;
} list;

void init_list(list *l) {
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
}

void add_to_list(list *l, char *name, char *email) {
  node *new_node = malloc(sizeof(node));
  new_node->name = strdup(name);
  new_node->email = strdup(email);
  new_node->next = NULL;

  if (l->head == NULL) {
    l->head = new_node;
    l->tail = new_node;
  } else {
    l->tail->next = new_node;
    l->tail = new_node;
  }

  l->size++;
}

void print_list(list *l) {
  node *current_node = l->head;

  while (current_node != NULL) {
    printf("%s, %s\n", current_node->name, current_node->email);
    current_node = current_node->next;
  }
}

void free_list(list *l) {
  node *current_node = l->head;

  while (current_node != NULL) {
    node *next_node = current_node->next;
    free(current_node->name);
    free(current_node->email);
    free(current_node);
    current_node = next_node;
  }

  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
}

int main() {
  list mailing_list;
  init_list(&mailing_list);

  add_to_list(&mailing_list, "Sir Reginald", "sir.reginald@example.com");
  add_to_list(&mailing_list, "Lady Jane", "lady.jane@example.com");
  add_to_list(&mailing_list, "Lord Edmund", "lord.edmund@example.com");

  print_list(&mailing_list);

  free_list(&mailing_list);

  return 0;
}