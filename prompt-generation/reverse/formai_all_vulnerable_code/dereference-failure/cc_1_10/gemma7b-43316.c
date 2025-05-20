//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 255
#define MAX_MSG_LEN 1024

typedef struct Node {
  char name[MAX_NAME_LEN];
  struct Node* next;
  struct Node* prev;
  char message[MAX_MSG_LEN];
} Node;

Node* head = NULL;
Node* tail = NULL;

void insert(char* name, char* message) {
  Node* newNode = malloc(sizeof(Node));

  strcpy(newNode->name, name);
  strcpy(newNode->message, message);

  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void print_list() {
  Node* current = head;

  while (current) {
    printf("%s: %s\n", current->name, current->message);
    current = current->next;
  }
}

int main() {
  insert("John Doe", "Hello, world!");
  insert("Jane Doe", "This is a message.");
  insert("Bill Smith", "How are you?");

  print_list();

  return 0;
}