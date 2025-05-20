//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
  struct Node* next;
  int data;
} Node;

typedef struct List {
  struct Node* head;
} List;

List* insert_at_tail(List* list, int data) {
  Node* new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
  } else {
    list->head->next = new_node;
  }

  return list;
}

void print_list(List* list) {
  Node* current = list->head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  List* list = malloc(sizeof(List));
  list->head = NULL;

  insert_at_tail(list, 10);
  insert_at_tail(list, 20);
  insert_at_tail(list, 30);
  insert_at_tail(list, 40);

  print_list(list);

  return 0;
}