//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR_LEN 256
#define MAX_FILE_LEN 1024

struct Node {
  char name[MAX_DIR_LEN];
  struct Node* next;
  struct Node* child;
};

struct File {
  char name[MAX_FILE_LEN];
  int size;
  struct File* next;
  struct File* parent;
};

void createDir(struct Node* node, char* dirName) {
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->name, dirName);
  newNode->next = NULL;
  newNode->child = NULL;
  node->child = newNode;
}

void createFile(struct File* file, char* fileName, int size) {
  struct File* newFile = malloc(sizeof(struct File));
  strcpy(newFile->name, fileName);
  newFile->size = size;
  newFile->next = NULL;
  newFile->parent = file;
  file->next = newFile;
}

int main() {
  struct Node* root = malloc(sizeof(struct Node));
  root->next = NULL;
  root->child = NULL;

  createDir(root, "home");
  createDir(root, "data");
  createDir(root, "tmp");

  createFile(root->child->child, "text.txt", 1024);
  createFile(root->child, "images.jpg", 10000);

  FILE* file = fopen(root->child->child->name, "r");
  printf("%s", fgets(file, 1024, NULL));
  fclose(file);

  return 0;
}