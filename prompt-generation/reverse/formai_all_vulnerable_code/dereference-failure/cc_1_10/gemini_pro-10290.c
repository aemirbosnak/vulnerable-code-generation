//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;

void push(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void print() {
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void pop() {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  struct node *temp = head;
  head = head->next;
  free(temp);
}

void insert_after(int data, int after) {
  struct node *temp = head;
  while (temp != NULL && temp->data != after) {
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Element not found\n");
    return;
  }
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = temp->next;
  temp->next = new_node;
}

void delete(int data) {
  struct node *temp = head;
  struct node *prev = NULL;
  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Element not found\n");
    return;
  }
  if (prev == NULL) {
    head = head->next;
  } else {
    prev->next = temp->next;
  }
  free(temp);
}

int main() {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  print();
  pop();
  print();
  insert_after(6, 3);
  print();
  delete(2);
  print();
  return 0;
}