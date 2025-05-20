//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_SIZE 20

typedef struct FileNode {
  char *name;
  int size;
  struct FileNode *next;
} FileNode;

typedef struct DirNode {
  char *name;
  FileNode **files;
  struct DirNode *next;
} DirNode;

DirNode *rootDir = NULL;

void createDir(char *name) {
  DirNode *newNode = malloc(sizeof(DirNode));
  newNode->name = strdup(name);
  newNode->files = NULL;
  newNode->next = rootDir;
  rootDir = newNode;
}

void createFile(char *name, int size) {
  FileNode *newNode = malloc(sizeof(FileNode));
  newNode->name = strdup(name);
  newNode->size = size;
  newNode->next = NULL;

  if (rootDir == NULL) {
    createDir("/");
  }

  DirNode *currentDir = rootDir;
  while (currentDir->next) {
    currentDir = currentDir->next;
  }

  currentDir->files = newNode;
}

void listFiles(DirNode *dir) {
  for (FileNode *file = dir->files; file; file = file->next) {
    printf("%s (size: %d)\n", file->name, file->size);
  }
}

int main() {
  createDir("/home");
  createDir("/home/user");
  createFile("/home/user/test.txt", 10);
  createFile("/home/user/another.txt", 20);

  listFiles(rootDir);

  return 0;
}