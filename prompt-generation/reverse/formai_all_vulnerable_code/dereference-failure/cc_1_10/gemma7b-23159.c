//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
  char name[256];
  struct Node* next;
  struct Node* dir;
} Node;

Node* head = NULL;

void createNode(char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;
  newNode->dir = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void createDir(char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;
  newNode->dir = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  newNode->dir = head;
}

void listFiles(char* dir) {
  Node* current = head;
  while (current) {
    if (strcmp(current->name, dir) == 0) {
      printf("%s\n", current->name);
    }
    current = current->next;
  }
}

int main() {
  createNode("John");
  createNode("Mary");
  createDir("Documents");
  createDir("Pictures");
  listFiles("Documents");

  return 0;
}