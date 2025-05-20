//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void printList(Node* head) {
  while (head) {
    printf("%c ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node* head = NULL;
  char input[MAX_BUFFER_SIZE];

  printf("Enter HTML code: ");
  fgets(input, MAX_BUFFER_SIZE, stdin);

  // Convert input into a linked list
  char* line = strtok(input, "\n");
  while (line) {
    insertAtTail(&head, line[0]);
    line = strtok(NULL, "\n");
  }

  // Remove duplicate characters
  Node* prev = NULL;
  Node* current = head;
  while (current) {
    if (prev && current->data == prev->data) {
      free(current);
      current = prev->next;
    } else {
      prev = current;
      current = current->next;
    }
  }

  // Print the beautified HTML code
  printList(head);

  return 0;
}