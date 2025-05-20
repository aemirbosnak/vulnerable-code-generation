//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *email;
  struct node *next;
} node;

typedef struct mailing_list {
  node *head;
  int size;
} mailing_list;

mailing_list *create_list() {
  mailing_list *list = malloc(sizeof(mailing_list));
  list->head = NULL;
  list->size = 0;
  return list;
}

void add_email(mailing_list *list, char *email) {
  node *new_node = malloc(sizeof(node));
  new_node->email = strdup(email);
  new_node->next = list->head;
  list->head = new_node;
  list->size++;
}

void remove_email(mailing_list *list, char *email) {
  node *current = list->head;
  node *previous = NULL;

  while (current != NULL && strcmp(current->email, email) != 0) {
    previous = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Email not found.\n");
    return;
  }

  if (previous == NULL) {
    list->head = current->next;
  } else {
    previous->next = current->next;
  }

  free(current->email);
  free(current);
  list->size--;
}

void print_list(mailing_list *list) {
  node *current = list->head;
  while (current != NULL) {
    printf("%s\n", current->email);
    current = current->next;
  }
}

int main() {
  mailing_list *list = create_list();

  add_email(list, "alice@example.com");
  add_email(list, "bob@example.com");
  add_email(list, "charlie@example.com");

  print_list(list);

  remove_email(list, "bob@example.com");

  print_list(list);

  return 0;
}