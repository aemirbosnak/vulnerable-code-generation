//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct Node {
  char name[MAX];
  struct Node* next;
} Node;

void createGraph(Node** head) {
  *head = (Node*)malloc(sizeof(Node));
  (*head)->name[0] = 'A';
  (*head)->next = NULL;

  Node* second = (Node*)malloc(sizeof(Node));
  second->name[0] = 'B';
  second->next = NULL;

  Node* third = (Node*)malloc(sizeof(Node));
  third->name[0] = 'C';
  third->next = NULL;

  Node* fourth = (Node*)malloc(sizeof(Node));
  fourth->name[0] = 'D';
  fourth->next = NULL;

  Node* fifth = (Node*)malloc(sizeof(Node));
  fifth->name[0] = 'E';
  fifth->next = NULL;

  (*head)->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = NULL;
}

int main() {
  Node* head = NULL;
  createGraph(&head);

  Node* current = head;
  while (current) {
    printf("%s ", current->name);
    current = current->next;
  }

  printf("\n");

  return 0;
}