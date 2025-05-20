//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: random
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct Node {
  char name[256];
  struct Node* next;
  struct Node* dir;
} Node;

void createNode(struct Node** head) {
  *head = malloc(sizeof(struct Node));
  (*head)->next = NULL;
  (*head)->dir = NULL;
  strcpy((*head)->name, "");
}

void addFile(struct Node* head, char* filename) {
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->name, filename);
  newNode->next = NULL;
  newNode->dir = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  head = newNode;
}

void addDir(struct Node* head, char* dirname) {
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->name, dirname);
  newNode->next = NULL;
  newNode->dir = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->dir = newNode;
  }

  head = newNode;
}

int main() {
  struct Node* root = NULL;

  // Create some files and directories
  addDir(root, "mydir");
  addDir(root, "anotherdir");
  addDir(root, "testdir");
  addFile(root, "file1.txt");
  addFile(root, "file2.txt");
  addFile(root, "image.jpg");

  // List all files and directories
  struct Node* current = root;
  while (current) {
    if (current->dir) {
      printf("%s\n", current->dir->name);
    } else if (current->name) {
      printf("%s\n", current->name);
    }
    current = current->next;
  }

  return 0;
}