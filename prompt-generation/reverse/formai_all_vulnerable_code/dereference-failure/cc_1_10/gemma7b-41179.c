//Gemma-7B DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LEN 256

typedef struct Node {
  char name[256];
  struct Node* next;
} Node;

Node* head = NULL;

void addCommand(char* cmd) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, cmd);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

int executeCommand(char* cmd) {
  for (Node* i = head; i; i = i->next) {
    if (strcmp(i->name, cmd) == 0) {
      return 1;
    }
  }

  return 0;
}

int main() {
  addCommand("ls");
  addCommand("pwd");
  addCommand("mkdir test");
  addCommand("cd test");
  addCommand("echo hello");

  if (executeCommand("ls") == 1) {
    printf("Files:");
    printf(" ls\n");
  }

  if (executeCommand("pwd") == 1) {
    printf("Current working directory:");
    printf(" pwd\n");
  }

  if (executeCommand("mkdir test") == 1) {
    printf("Directory created:");
    printf(" mkdir test\n");
  }

  if (executeCommand("cd test") == 1) {
    printf("Changed directory:");
    printf(" cd test\n");
  }

  if (executeCommand("echo hello") == 1) {
    printf("Output:");
    printf(" echo hello\n");
  }

  return 0;
}