//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_SIZE 1024

typedef struct Node {
  char name[256];
  struct Node* next;
  struct Node* dir;
  FILE* file;
} Node;

void mkdir(Node* node, char* name) {
  if (node->dir == NULL) {
    node->dir = malloc(sizeof(struct Node));
  }
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  newNode->next = node->dir->next;
  node->dir->next = newNode;
  newNode->dir = NULL;
  newNode->file = NULL;
}

void mkfile(Node* node, char* name, int size) {
  if (node->file == NULL) {
    node->file = fopen(name, "w");
  }
  FILE* newFile = fopen(name, "a");
  fclose(newFile);
  node->file = newFile;
  fprintf(node->file, "%d", size);
}

int main() {
  Node* root = malloc(sizeof(struct Node));
  strcpy(root->name, "Root");
  root->dir = NULL;
  root->file = NULL;

  mkdir(root, "Home");
  mkdir(root, "Games");
  mkdir(root, "Documents");

  mkfile(root->dir->next, "test.txt", 1024);
  mkfile(root->dir->next, "another.txt", 512);

  FILE* file = fopen("Home/test.txt", "r");
  int size = fread(file, 1, 4, file);
  printf("File size: %d", size);

  return 0;
}