//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EMAIL_LENGTH 255

typedef struct Node {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  struct Node* next;
} Node;

Node* insertNode(Node* head) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  scanf("Enter name: ", newNode->name);
  scanf("Enter email: ", newNode->email);

  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }

  return head;
}

void printNodes(Node* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Email: %s\n", head->email);
    printf("\n");
    head = head->next;
  }
}

int main() {
  Node* head = NULL;

  // Insert nodes
  insertNode(head);
  insertNode(head);
  insertNode(head);

  // Print nodes
  printNodes(head);

  return 0;
}