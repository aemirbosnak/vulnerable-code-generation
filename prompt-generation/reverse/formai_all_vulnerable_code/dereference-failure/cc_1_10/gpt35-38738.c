//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
  int size;
} LinkedList;

void addNode(LinkedList* list, int data) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (list->size == 0) {
    list->head = new_node;
  } else {
    Node* cur_node = list->head;
    while (cur_node->next != NULL) {
      cur_node = cur_node->next;
    }
    cur_node->next = new_node;
  }

  list->size++;
}

void printList(LinkedList list) {
  printf("Head -> ");
  Node* cur_node = list.head;
  while (cur_node != NULL) {
    printf("%d -> ", cur_node->data);
    cur_node = cur_node->next;
  }
  printf("NULL\n");
}

int main() {
  LinkedList list = {NULL, 0};
  addNode(&list, 1);
  addNode(&list, 2);
  addNode(&list, 3);
  addNode(&list, 4);
  
  printList(list);

  return 0;
}