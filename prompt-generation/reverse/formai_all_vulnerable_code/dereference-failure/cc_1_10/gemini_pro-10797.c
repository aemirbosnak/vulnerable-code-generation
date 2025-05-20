//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *email;
  struct node *next;
} node;

typedef struct mailing_list {
  char *name;
  node *head;
} mailing_list;

mailing_list *create_mailing_list(char *name) {
  mailing_list *list = malloc(sizeof(mailing_list));
  list->name = strdup(name);
  list->head = NULL;
  return list;
}

void add_email_to_list(mailing_list *list, char *email) {
  node *new_node = malloc(sizeof(node));
  new_node->email = strdup(email);
  new_node->next = list->head;
  list->head = new_node;
}

void remove_email_from_list(mailing_list *list, char *email) {
  node *curr_node = list->head;
  node *prev_node = NULL;

  while (curr_node != NULL) {
    if (strcmp(curr_node->email, email) == 0) {
      if (prev_node == NULL) {
        list->head = curr_node->next;
      } else {
        prev_node->next = curr_node->next;
      }
      free(curr_node->email);
      free(curr_node);
      return;
    }
    prev_node = curr_node;
    curr_node = curr_node->next;
  }
}

void print_mailing_list(mailing_list *list) {
  node *curr_node = list->head;

  printf("Mailing List: %s\n", list->name);
  while (curr_node != NULL) {
    printf("%s\n", curr_node->email);
    curr_node = curr_node->next;
  }
}

void free_mailing_list(mailing_list *list) {
  node *curr_node = list->head;
  node *next_node;

  while (curr_node != NULL) {
    next_node = curr_node->next;
    free(curr_node->email);
    free(curr_node);
    curr_node = next_node;
  }

  free(list->name);
  free(list);
}

int main() {
  mailing_list *list = create_mailing_list("My Mailing List");

  add_email_to_list(list, "email1@example.com");
  add_email_to_list(list, "email2@example.com");
  add_email_to_list(list, "email3@example.com");

  print_mailing_list(list);

  remove_email_from_list(list, "email2@example.com");

  print_mailing_list(list);

  free_mailing_list(list);

  return 0;
}