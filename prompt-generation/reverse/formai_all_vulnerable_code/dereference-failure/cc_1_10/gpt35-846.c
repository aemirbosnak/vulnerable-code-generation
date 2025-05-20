//FormAI DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* create_node(int data) {
  Node* new_node = (Node*) malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

Node* insert_node(Node* head, int data) {
  Node* new_node = create_node(data);
  if (head == NULL) {
    head = new_node;
  } else {
    Node* current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
  return head;
}

bool is_empty(Node* head) {
  return head == NULL;
}

void visualize_list(Node* head) {
  printf("List: ");
  if (is_empty(head)) {
    printf("Empty");
  } else {
    Node* current_node = head;
    while (current_node != NULL) {
      printf("%d",current_node->data);
      current_node = current_node->next;
      if (current_node != NULL) {
          printf(" -> ");
      }
    }
  }
  printf("\n");
}

int main() {
  Node* my_list = NULL;
  my_list = insert_node(my_list, 1);
  my_list = insert_node(my_list, 2);
  my_list = insert_node(my_list, 3);
  my_list = insert_node(my_list, 4);
  my_list = insert_node(my_list, 5);
  my_list = insert_node(my_list, 6);
  visualize_list(my_list);
  return 0;
}