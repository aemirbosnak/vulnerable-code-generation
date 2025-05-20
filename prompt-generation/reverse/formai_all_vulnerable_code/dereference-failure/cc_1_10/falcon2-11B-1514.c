//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* head = NULL;

void insert(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}

void printList() {
  struct Node* temp = head;
  while (temp!= NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void delete(int key) {
  struct Node* temp = head;
  if (temp == NULL) {
    printf("List is empty\n");
    return;
  }
  if (temp->data == key) {
    struct Node* temp2 = temp->next;
    free(temp);
    head = temp2;
    return;
  }
  while (temp!= NULL && temp->data!= key) {
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Key not found\n");
    return;
  }
  struct Node* temp2 = temp->next;
  struct Node* next = temp->next->next;
  free(temp);
  temp = next;
  head = temp;
}

int main() {
  insert(1);
  insert(2);
  insert(3);
  printList();
  delete(2);
  printList();
  return 0;
}