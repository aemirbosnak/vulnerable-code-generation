//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
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

struct list *create_list() {
  struct list *list = malloc(sizeof(struct list));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void add_to_list(struct list *list, char *name, char *email) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->name = strdup(name);
  new_node->email = strdup(email);
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

void remove_from_list(struct list *list, char *name) {
  struct node *current = list->head;
  struct node *previous = NULL;

  while (current != NULL) {
    if (strcmp(current->name, name) == 0) {
      if (previous == NULL) {
        list->head = current->next;
      } else {
        previous->next = current->next;
      }

      free(current->name);
      free(current->email);
      free(current);

      if (list->tail == current) {
        list->tail = previous;
      }

      return;
    }

    previous = current;
    current = current->next;
  }
}

void print_list(struct list *list) {
  struct node *current = list->head;

  while (current != NULL) {
    printf("%s <%s>\n", current->name, current->email);
    current = current->next;
  }
}

void free_list(struct list *list) {
  struct node *current = list->head;

  while (current != NULL) {
    struct node *next = current->next;

    free(current->name);
    free(current->email);
    free(current);

    current = next;
  }

  free(list);
}

int main() {
  struct list *list = create_list();

  add_to_list(list, "Donald Knuth", "knuth@stanford.edu");
  add_to_list(list, "Edsger Dijkstra", "dijkstra@acm.org");
  add_to_list(list, "Alan Turing", "turing@cambridge.org");

  print_list(list);

  remove_from_list(list, "Edsger Dijkstra");

  print_list(list);

  free_list(list);

  return 0;
}