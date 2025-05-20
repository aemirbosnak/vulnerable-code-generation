//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct File {
  char name[25];
  struct File* next;
  struct Dir* dir;
} File;

typedef struct Dir {
  char name[25];
  struct Dir* next;
  File* files;
} Dir;

Dir* root = NULL;

void createFile(char* name) {
  File* file = malloc(sizeof(File));
  strcpy(file->name, name);
  file->next = NULL;
  file->dir = root;

  if (root == NULL) {
    root = file;
  } else {
    root->next = file;
    root = file;
  }
}

void listFiles(Dir* dir) {
  File* file = dir->files;
  while (file) {
    printf("%s\n", file->name);
    file = file->next;
  }
}

int main() {
  createFile("a.txt");
  createFile("b.txt");
  createFile("c.txt");
  listFiles(root->files->dir);

  return 0;
}