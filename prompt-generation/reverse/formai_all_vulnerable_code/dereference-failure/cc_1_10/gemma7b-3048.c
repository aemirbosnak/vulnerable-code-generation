//Gemma-7B DATASET v1.0 Category: Memory management ; Style: single-threaded
// Single-threaded memory management example program

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

struct Node {
  char *data;
  struct Node *next;
};

struct Node *head = NULL;

void insert(char *data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = (char *)malloc(MAX_SIZE);
  strcpy(newNode->data, data);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Node *temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void traverse() {
  struct Node *temp = head;
  while (temp) {
    printf("%s ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  insert("John Doe");
  insert("Jane Doe");
  insert("Peter Pan");
  traverse();

  free(head->data);
  free(head);
  return 0;
}