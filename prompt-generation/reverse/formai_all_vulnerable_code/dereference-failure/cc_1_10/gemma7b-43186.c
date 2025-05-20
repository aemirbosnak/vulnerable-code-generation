//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 25
#define MAX_MSG_LENGTH 200

struct Node {
  char name[MAX_NAME_LENGTH];
  char message[MAX_MSG_LENGTH];
  struct Node* next;
};

struct Node* insertNode(struct Node* head, char* name, char* message) {
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  strcpy(newNode->message, message);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

struct Node* searchNode(struct Node* head, char* name) {
  struct Node* temp = head;
  while (temp) {
    if (strcmp(temp->name, name) == 0) {
      return temp;
    }
    temp = temp->next;
  }

  return NULL;
}

void printNode(struct Node* head) {
  struct Node* temp = head;
  while (temp) {
    printf("%s: %s\n", temp->name, temp->message);
    temp = temp->next;
  }
}

int main() {
  struct Node* head = NULL;

  insertNode(head, "John Doe", "Hello, world!");
  insertNode(head, "Jane Doe", "How are you?");
  insertNode(head, "Bob Smith", "Not bad, I guess.");

  printNode(head);

  struct Node* foundNode = searchNode(head, "Jane Doe");

  if (foundNode) {
    printf("%s: %s\n", foundNode->name, foundNode->message);
  } else {
    printf("Node not found.\n");
  }

  return 0;
}