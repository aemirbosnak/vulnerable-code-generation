//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
  char name[20];
  struct Node* next;
  struct Node* dir;
} Node;

Node* newNode(char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;
  newNode->dir = NULL;
  return newNode;
}

void addDir(Node* node, char* dirName) {
  Node* newDir = newNode(dirName);
  if (node->dir == NULL) {
    node->dir = newDir;
  } else {
    node->dir->next = newDir;
  }
}

void addFile(Node* node, char* fileName) {
  Node* newFile = newNode(fileName);
  if (node->dir == NULL) {
    printf("Error: No directory selected.\n");
  } else {
    node->dir->next = newFile;
  }
}

void listDir(Node* node) {
  printf("Directory: ");
  for (Node* dir = node->dir; dir; dir = dir->next) {
    printf("%s ", dir->name);
  }
  printf("\n");
}

void listFiles(Node* node) {
  printf("Files: ");
  for (Node* file = node->dir->next; file; file = file->next) {
    printf("%s ", file->name);
  }
  printf("\n");
}

int main() {
  Node* root = newNode("root");
  addDir(root, "home");
  addDir(root, "office");
  addDir(root, "documents");
  addFile(root->dir->dir, "my.txt");
  addFile(root->dir->dir, "photo.jpg");
  addFile(root->dir->dir, "notes.doc");
  listFiles(root);
  listDir(root);

  return 0;
}