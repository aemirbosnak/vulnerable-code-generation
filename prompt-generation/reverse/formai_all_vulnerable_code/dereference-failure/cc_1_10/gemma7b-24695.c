//Gemma-7B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct Node {
  char name[255];
  struct Node* next;
} Node;

void insertNode(Node** head, char* name) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

int main() {
  Node* head = NULL;

  char cmd[MAX_CMD_LEN];

  while (1) {
    printf("Enter command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    char* cmdPtr = strtok(cmd, " ");

    if (!strcmp(cmdPtr, "add")) {
      insertNode(&head, strtok(NULL, " "));
    } else if (!strcmp(cmdPtr, "list")) {
      for (Node* node = head; node; node = node->next) {
        printf("%s\n", node->name);
      }
    } else if (!strcmp(cmdPtr, "exit")) {
      exit(0);
    } else {
      printf("Invalid command.\n");
    }
  }

  return 0;
}