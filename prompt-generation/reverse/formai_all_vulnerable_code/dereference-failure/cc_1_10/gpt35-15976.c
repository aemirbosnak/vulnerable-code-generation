//FormAI DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void add_node(struct Node** head, int val) {
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = val;
  new_node->next = (*head);
  (*head) = new_node;
}

void print_list(struct Node* head) {
  printf("[ ");
  while(head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("]\n");
}

int main() {
  struct Node* list = NULL;

  printf("Let's create a linked list with some integer values!\n");

  add_node(&list, 4);
  add_node(&list, 2);
  add_node(&list, 6);
  add_node(&list, 8);
  add_node(&list, 1);

  printf("Our linked list is ");
  print_list(list);

  printf("Now let's reverse the list!\n");

  struct Node *prev = NULL, *current = list, *next = NULL;
  
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  list = prev;

  printf("The reversed linked list is ");
  print_list(list);

  return 0;
}