//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_DIR 5

typedef struct File {
  char name[256];
  struct File* next;
  struct Dir* dir;
} File;

typedef struct Dir {
  char name[256];
  struct Dir* next;
  File* files;
} Dir;

File* createFile(char* name) {
  File* file = malloc(sizeof(File));
  strcpy(file->name, name);
  file->next = NULL;
  file->dir = NULL;
  return file;
}

Dir* createDir(char* name) {
  Dir* dir = malloc(sizeof(Dir));
  strcpy(dir->name, name);
  dir->next = NULL;
  dir->files = NULL;
  return dir;
}

void listFiles(Dir* dir) {
  File* file = dir->files;
  while (file) {
    printf("%s\n", file->name);
    file = file->next;
  }
}

int main() {
  Dir* root = createDir("root");
  File* file1 = createFile("file1.txt");
  File* file2 = createFile("file2.txt");
  file1->dir = root;
  file2->dir = root;
  listFiles(root);
  return 0;
}