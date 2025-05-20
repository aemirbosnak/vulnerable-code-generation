//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct File {
  char name[20];
  struct File* next;
} File;

typedef struct Directory {
  char name[20];
  File** dir;
  struct Directory* next;
} Directory;

Directory* root;

void mkdir(char* name) {
  Directory* newDir = malloc(sizeof(Directory));
  strcpy(newDir->name, name);
  newDir->dir = NULL;
  newDir->next = root;
  root = newDir;
}

void mkfile(char* name) {
  File* newFile = malloc(sizeof(File));
  strcpy(newFile->name, name);
  newFile->next = NULL;
  Directory* currentDir = root;
  while (currentDir) {
    if (strcmp(currentDir->name, name) == 0) {
      currentDir->dir = newFile;
      return;
    }
    currentDir = currentDir->next;
  }
  mkdir(name);
  mkfile(name);
}

void ls() {
  Directory* currentDir = root;
  while (currentDir) {
    printf("%s:\n", currentDir->name);
    File* file = currentDir->dir;
    while (file) {
      printf("%s\n", file->name);
    }
    currentDir = currentDir->next;
  }
}

int main() {
  mkdir("home");
  mkfile("home/foo.txt");
  mkfile("home/bar.txt");
  ls();
  return 0;
}