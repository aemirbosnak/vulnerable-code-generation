//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ Mailing_LIST_SIZE 100

typedef struct Node {
  char name[MAX_NAME_LENGTH];
  struct Node* next;
} Node;

Node* InsertAtTail(Node* head, char* name) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void PrintList(Node* head) {
  Node* current = head;
  while (current) {
    printf("%s\n", current->name);
    current = current->next;
  }
}

int main() {
  Node* head = NULL;

  char name[MAX_NAME_LENGTH];

  printf("Enter name: ");
  scanf("%s", name);
  InsertAtTail(head, name);

  printf("Enter name: ");
  scanf("%s", name);
  InsertAtTail(head, name);

  printf("Enter name: ");
  scanf("%s", name);
  InsertAtTail(head, name);

  PrintList(head);

  return 0;
}