//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: distributed
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

Node* newNode(char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;
  newNode->dir = NULL;
  newNode->file = NULL;
  return newNode;
}

void insertDir(Node* node, char* dirName) {
  Node* newDir = newNode(dirName);
  if (node->dir == NULL) {
    node->dir = newDir;
  } else {
    insertDir(node->dir, dirName);
  }
}

void insertFile(Node* node, char* fileName, int fileSize) {
  Node* newFile = newNode(fileName);
  newFile->file = fopen(fileName, "w");
  if (node->file == NULL) {
    node->file = newFile;
  } else {
    insertFile(node->file, fileName, fileSize);
  }
}

void listDir(Node* node) {
  printf("%s\n", node->name);
  if (node->dir) {
    listDir(node->dir);
  }
}

void listFile(Node* node) {
  printf("%s\n", node->name);
  if (node->file) {
    listFile(node->file);
  }
}

int main() {
  Node* root = newNode("root");
  insertDir(root, "dir1");
  insertDir(root, "dir2");
  insertFile(root, "file1.txt", 1024);
  insertFile(root, "file2.txt", 512);

  listDir(root);
  listFile(root);

  return 0;
}