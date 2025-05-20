//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_SIZE 50

typedef struct Node {
  char name[256];
  struct Node* next;
  struct Node* parent;
  FILE* file;
} Node;

Node* newNode(char* name) {
  Node* node = (Node*)malloc(sizeof(Node));
  strcpy(node->name, name);
  node->next = NULL;
  node->parent = NULL;
  node->file = NULL;
  return node;
}

void addToDir(Node* dir, Node* newNode) {
  if (dir->next == NULL) {
    dir->next = newNode;
  } else {
    addToDir(dir->next, newNode);
  }
}

void listDir(Node* dir) {
  printf("%s:", dir->name);
  for (Node* node = dir->next; node; node = node->next) {
    printf(" %s", node->name);
  }
  printf("\n");
}

int main() {
  Node* root = newNode("root");

  Node* dir1 = newNode("dir1");
  addToDir(root, dir1);

  Node* dir2 = newNode("dir2");
  addToDir(root, dir2);

  Node* file1 = newNode("file1.txt");
  addToDir(dir1, file1);

  Node* file2 = newNode("file2.txt");
  addToDir(dir2, file2);

  listDir(root);

  return 0;
}