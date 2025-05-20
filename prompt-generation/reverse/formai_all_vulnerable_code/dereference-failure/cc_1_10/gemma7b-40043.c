//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char name[256];
  struct Node* next;
  struct Node* parent;
  FILE* file;
  int isDir;
};

typedef struct Node Node;

void mkdir(Node* node);
void rmdir(Node* node);
void listDir(Node* node);

int main() {
  Node* root = malloc(sizeof(Node));
  root->name[0] = '/';
  root->name[1] = '\0';
  root->isDir = 1;
  root->next = NULL;
  root->parent = NULL;
  root->file = NULL;

  mkdir(root);
  mkdir(root->next = malloc(sizeof(Node)));
  mkdir(root->next->next = malloc(sizeof(Node)));

  listDir(root);

  rmdir(root->next);

  listDir(root);

  return 0;
}

void mkdir(Node* node) {
  FILE* file = fopen(node->name, "w");
  node->file = file;
  node->isDir = 1;
  fclose(file);
}

void rmdir(Node* node) {
  fclose(node->file);
  free(node);
  node = NULL;
  node->isDir = 0;
}

void listDir(Node* node) {
  printf("%s\n", node->name);
  if (node->next) {
    listDir(node->next);
  }
}