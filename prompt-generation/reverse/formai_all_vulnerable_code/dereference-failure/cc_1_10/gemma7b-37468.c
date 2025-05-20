//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
  char name[256];
  struct File* next;
  struct File* parent;
  int size;
  FILE* file;
} File;

File* root = NULL;
File* current = NULL;

void init() {
  root = NULL;
  current = NULL;
}

void mkdir(char* name) {
  File* newDir = (File*)malloc(sizeof(File));
  strcpy(newDir->name, name);
  newDir->next = NULL;
  newDir->parent = current;
  newDir->size = 0;
  newDir->file = NULL;

  if (root == NULL) {
    root = newDir;
  } else {
    current->next = newDir;
  }
  current = newDir;
}

void cd(char* name) {
  File* found = NULL;
  current = root;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      found = current;
      break;
    }
    current = current->next;
  }

  if (found) {
    current = found;
  } else {
    printf("Error: File not found.\n");
  }
}

void list() {
  current = root;

  while (current) {
    printf("%s\n", current->name);
    current = current->next;
  }
}

int main() {
  init();
  mkdir("home");
  mkdir("home/documents");
  mkdir("home/pictures");
  cd("home");
  list();

  return 0;
}