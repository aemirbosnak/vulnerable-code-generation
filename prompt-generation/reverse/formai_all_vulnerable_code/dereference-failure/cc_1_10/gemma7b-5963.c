//Gemma-7B DATASET v1.0 Category: System administration ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_CMD_LEN 255

typedef struct Node {
  char name[20];
  struct Node* next;
} Node;

typedef struct Command {
  char cmd[MAX_CMD_LEN];
  struct Command* next;
} Command;

Node* head = NULL;
Command* tail = NULL;

void insertNode(char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void insertCommand(char* cmd) {
  Command* newCommand = (Command*)malloc(sizeof(Command));
  strcpy(newCommand->cmd, cmd);
  newCommand->next = NULL;

  if (tail == NULL) {
    tail = newCommand;
  } else {
    tail->next = newCommand;
    tail = newCommand;
  }
}

int main() {
  insertNode("John Doe");
  insertNode("Jane Doe");
  insertNode("Peter Pan");

  insertCommand("Hello, world!");
  insertCommand("How are you?");
  insertCommand("I'm fine, thank you.");

  Node* current = head;
  Command* command = tail;

  while (current) {
    printf("Name: %s\n", current->name);
    current = current->next;
  }

  while (command) {
    printf("Command: %s\n", command->cmd);
    command = command->next;
  }

  return 0;
}