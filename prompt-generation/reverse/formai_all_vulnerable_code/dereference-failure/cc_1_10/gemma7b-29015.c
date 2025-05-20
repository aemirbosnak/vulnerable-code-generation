//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct LinkedList {
  struct Node* head;
  struct Node* tail;
  int size;
};

struct LinkedList* insertAtTail(struct LinkedList* list, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->size++;

  return list;
}

struct LinkedList* insertAtHead(struct LinkedList* list, int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    newNode->next = list->head;
    list->head = newNode;
  }

  list->size++;

  return list;
}

void printList(struct LinkedList* list) {
  struct Node* current = list->head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

int main() {
  struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  insertAtTail(list, 10);
  insertAtTail(list, 20);
  insertAtHead(list, 30);
  insertAtHead(list, 40);

  printList(list);

  return 0;
}