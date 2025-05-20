//Gemma-7B DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct Node {
  char name[25];
  struct Node* next;
} Node;

Node* insertNode(Node* head, char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int main() {
  Node* head = NULL;

  char cmd[MAX_CMD_LEN];

  while (1) {
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    char* cmdArgs[MAX_CMD_LEN] = { NULL };
    int i = 0;

    // Parse the command line arguments
    for (char* arg = strtok(cmd, " "); arg; arg = strtok(NULL, " ")) {
      cmdArgs[i++] = arg;
    }

    // Check if the command is "add"
    if (strcmp(cmdArgs[0], "add") == 0) {
      // Add a new node to the list
      insertNode(head, cmdArgs[1]);
    }

    // Check if the command is "list"
    else if (strcmp(cmdArgs[0], "list") == 0) {
      // List all nodes in the list
      for (Node* node = head; node; node = node->next) {
        printf("%s\n", node->name);
      }
    }

    // Check if the command is "exit"
    else if (strcmp(cmdArgs[0], "exit") == 0) {
      // Exit the program
      exit(0);
    }

    // Invalid command
    else {
      printf("Error: Invalid command.\n");
    }
  }

  return 0;
}