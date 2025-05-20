//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>

typedef struct node {
  int value;
  struct node* next;
} node;

node* head = NULL;

void addNode(int value) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->value = value;
  newNode->next = head;
  head = newNode;
}

void printList() {
  node* current = head;
  while (current!= NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

void deleteNode(int value) {
  node* current = head;
  node* prev = NULL;
  while (current!= NULL && current->value!= value) {
    prev = current;
    current = current->next;
  }
  if (current == NULL) {
    printf("Value not found in the list\n");
  } else {
    prev->next = current->next;
    free(current);
  }
}

int search(int value) {
  node* current = head;
  while (current!= NULL && current->value!= value) {
    current = current->next;
  }
  if (current == NULL) {
    return 0;
  } else {
    return 1;
  }
}

int getSize() {
  int size = 0;
  node* current = head;
  while (current!= NULL) {
    size++;
    current = current->next;
  }
  return size;
}

int isEmpty() {
  return head == NULL;
}

int main() {
  addNode(1);
  addNode(2);
  addNode(3);
  printList();
  deleteNode(1);
  printf("Value 1 deleted\n");
  printList();
  deleteNode(2);
  printf("Value 2 deleted\n");
  printList();
  deleteNode(3);
  printf("Value 3 deleted\n");
  printList();
  printf("Size of the list: %d\n", getSize());
  printf("Is the list empty? %d\n", isEmpty());
  if (search(1)) {
    printf("Value 1 found in the list\n");
  } else {
    printf("Value 1 not found in the list\n");
  }
  if (search(2)) {
    printf("Value 2 found in the list\n");
  } else {
    printf("Value 2 not found in the list\n");
  }
  if (search(3)) {
    printf("Value 3 found in the list\n");
  } else {
    printf("Value 3 not found in the list\n");
  }
  return 0;
}