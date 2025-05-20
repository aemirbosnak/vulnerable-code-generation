//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILE 20

struct Node {
  char name[20];
  struct Node* next;
  struct Node* dir;
};

void createNode(struct Node** head, char* name) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;
  newNode->dir = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void createDir(struct Node* dirNode, char* dirName) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->name, dirName);
  newNode->next = NULL;
  newNode->dir = dirNode;

  dirNode->dir = newNode;
}

void listDir(struct Node* dirNode) {
  struct Node* currentDir = dirNode->dir;
  while (currentDir) {
    printf("%s\n", currentDir->name);
    currentDir = currentDir->next;
  }
}

int main() {
  struct Node* head = NULL;
  createNode(&head, "root");

  createDir(head->dir, "user");
  createDir(head->dir, "admin");
  createDir(head->dir, "public");

  listDir(head->dir);

  return 0;
}