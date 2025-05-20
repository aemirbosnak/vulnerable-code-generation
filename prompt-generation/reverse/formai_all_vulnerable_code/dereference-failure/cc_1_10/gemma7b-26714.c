//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char name[256];
  struct Node* next;
  struct Node* child;
};

void createDirectory(struct Node* node, char* dirName) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->name, dirName);
  newNode->next = NULL;
  newNode->child = NULL;

  if (node->child == NULL) {
    node->child = newNode;
  } else {
    struct Node* tempNode = node->child;
    while (tempNode->next) {
      tempNode = tempNode->next;
    }
    tempNode->next = newNode;
  }
}

void listDirectory(struct Node* node) {
  printf("%s\n", node->name);
  if (node->child) {
    struct Node* tempNode = node->child;
    while (tempNode) {
      listDirectory(tempNode);
    }
  }
}

int main() {
  struct Node* root = (struct Node*)malloc(sizeof(struct Node));
  strcpy(root->name, "root");
  root->next = NULL;
  root->child = NULL;

  createDirectory(root, "dir1");
  createDirectory(root, "dir2");
  createDirectory(root, "dir3");

  listDirectory(root);

  return 0;
}