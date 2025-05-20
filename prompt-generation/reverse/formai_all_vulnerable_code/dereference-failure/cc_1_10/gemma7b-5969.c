//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_NUM_LENGTH 10

typedef struct Node {
  char name[MAX_NAME_LENGTH];
  int num;
  struct Node* next;
} Node;

Node* insertNode(Node* head, char* name, int num) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->num = num;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  Node* tail = head;
  while (tail->next) {
    tail = tail->next;
  }

  tail->next = newNode;

  return head;
}

void searchName(Node* head, char* name) {
  Node* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      printf("Phone number: %d\n", current->num);
      return;
    }
    current = current->next;
  }

  printf("Name not found.\n");
}

int main() {
  Node* head = NULL;

  insertNode(head, "John Doe", 123);
  insertNode(head, "Jane Doe", 456);
  insertNode(head, "Peter Pan", 987);

  searchName(head, "John Doe");
  searchName(head, "Jane Doe");
  searchName(head, "Mr. T");

  return 0;
}