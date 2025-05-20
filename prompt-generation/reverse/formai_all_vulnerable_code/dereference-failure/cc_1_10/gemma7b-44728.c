//Gemma-7B DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct Node {
  char name[255];
  struct Node* next;
} Node;

void insert(Node** head, char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int main() {
  Node* head = NULL;

  insert(&head, "John");
  insert(&head, "Alice");
  insert(&head, "Bob");

  char cmd[MAX_CMD_LEN];
  printf("Enter command: ");
  scanf("%s", cmd);

  char* cmd_words[MAX_CMD_LEN];
  int num_words = 0;

  // Tokenize the command
  char* token = strtok(cmd, " ");
  while (token) {
    cmd_words[num_words++] = token;
    token = strtok(NULL, " ");
  }

  // Check if the command is to print the list
  if (strcmp(cmd_words[0], "print") == 0) {
    Node* current = head;
    while (current) {
      printf("%s ", current->name);
      current = current->next;
    }
    printf("\n");
  }

  // Other commands can be implemented here...

  return 0;
}