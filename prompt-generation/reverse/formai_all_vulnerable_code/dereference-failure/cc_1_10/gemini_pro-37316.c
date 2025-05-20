//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *head = NULL;

Node *create(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert(int data) {
  Node *new_node = create(data);
  if (head == NULL) {
    head = new_node;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

void print() {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void delete(int data) {
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL) {
    if (temp->data == data) {
      if (prev == NULL) {
        head = temp->next;
      } else {
        prev->next = temp->next;
      }
      free(temp);
      return;
    }
    prev = temp;
    temp = temp->next;
  }
}

int main() {
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  print();
  delete(2);
  print();
  return 0;
}