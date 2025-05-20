//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR_LEN 255
#define MAX_FILE_NAME_LEN 255

typedef struct FileNode {
  char *name;
  struct FileNode *next;
  struct Directory *directory;
} FileNode;

typedef struct Directory {
  char *name;
  struct Directory *next;
  FileNode **files;
} Directory;

Directory *rootDir;

void createFile(char *name, Directory *directory) {
  FileNode *newNode = malloc(sizeof(FileNode));
  newNode->name = strdup(name);
  newNode->next = NULL;
  newNode->directory = directory;

  if (directory->files == NULL) {
    directory->files = newNode;
  } else {
    directory->files = newNode;
  }
}

void listFiles(Directory *directory) {
  FileNode *node = directory->files;
  while (node) {
    printf("%s\n", node->name);
    node = node->next;
  }
}

int main() {
  rootDir = malloc(sizeof(Directory));
  rootDir->name = "/";
  rootDir->next = NULL;
  rootDir->files = NULL;

  createFile("test.txt", rootDir);
  createFile("mydir", rootDir);
  createFile("another.txt", rootDir);
  listFiles(rootDir);

  return 0;
}