//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct file {
  char name[256];
  struct file* next;
} file;

typedef struct dir {
  char name[256];
  struct dir* next;
  file** files;
} dir;

dir* root;

void createFile(char* name) {
  file* newFile = (file*)malloc(sizeof(file));
  strcpy(newFile->name, name);
  newFile->next = NULL;

  if (root == NULL) {
    root = (dir*)malloc(sizeof(dir));
    strcpy(root->name, "/");
    root->next = NULL;
    root->files = &newFile;
  } else {
    dir* currentDir = root;
    while (currentDir->next) {
      currentDir = currentDir->next;
    }
    currentDir->next = (dir*)malloc(sizeof(dir));
    strcpy(currentDir->next->name, name);
    currentDir->next->files = &newFile;
  }
}

void listFiles(dir* currentDir) {
  for (file* fileIter = currentDir->files; fileIter; fileIter = fileIter->next) {
    printf("%s\n", fileIter->name);
  }
}

int main() {
  createFile("foo.txt");
  createFile("bar.txt");
  listFiles(root);

  return 0;
}