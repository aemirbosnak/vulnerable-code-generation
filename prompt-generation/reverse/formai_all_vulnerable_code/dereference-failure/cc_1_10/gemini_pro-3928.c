//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define the listnode and the list structure
typedef struct node {
  char *email;
  struct node *next;
} node;
typedef struct list {
  node *head;
  unsigned int size;
} list;

// Initialises the list
list *init_list() {
  list *l = (list *)malloc(sizeof(list));
  l->head = NULL;
  l->size = 0;
  return l;
}

// Adds a new node to the list
void add_node(list *l, char *email) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->email = (char *)malloc(strlen(email) + 1);
  strcpy(new_node->email, email);
  new_node->next = l->head;
  l->head = new_node;
  l->size++;
}

// Prints the list
void print_list(list *l) {
  node *curr = l->head;
  while (curr != NULL) {
	  printf("%s\n", curr->email);
    curr = curr->next;
  }
}

// Deletes a node from the list
void delete_node(list *l, char *email) {
  node *curr = l->head;
  node *prev = NULL;
  while (curr != NULL && strcmp(curr->email, email) != 0) {
    prev = curr;
    curr = curr->next;
  }
  if (curr == NULL) {
    printf("Email not found\n");
    return;
  }
  if (prev == NULL) {
    l->head = curr->next;
  } else {
    prev->next = curr->next;
  }
  free(curr->email);
  free(curr);
  l->size--;
}

// Finds a node from the list
node *find_node(list *l, char *email) {
  node *curr = l->head;
  while (curr != NULL && strcmp(curr->email, email) != 0) {
    curr = curr->next;
  }
  return curr;
}

// Sorts the list
void sort_list(list *l) {
  node *curr = l->head;
  node *prev = NULL;
  while (curr != NULL) {
    node *min = curr;
    node *tmp = curr->next;
    while (tmp != NULL) {
      if (strcmp(tmp->email, min->email) < 0) {
        min = tmp;
      }
      tmp = tmp->next;
    }
    if (min != curr) {
      if (prev == NULL) {
        l->head = min;
      } else {
        prev->next = min;
      }
      tmp = min->next;
      min->next = curr;
      curr->next = tmp;
    }
    prev = curr;
    curr = curr->next;
  }
}

// Main function
int main() {
  list *l = init_list();
  add_node(l, "john@example.com");
  add_node(l, "mary@example.com");
  add_node(l, "bob@example.com");
  print_list(l);
  delete_node(l, "bob@example.com");
  print_list(l);
  node *n = find_node(l, "john@example.com");
  if (n != NULL) {
    printf("Found node with email: %s\n", n->email);
  } else {
    printf("Node not found\n");
  }
  sort_list(l);
  print_list(l);
  return 0;
}