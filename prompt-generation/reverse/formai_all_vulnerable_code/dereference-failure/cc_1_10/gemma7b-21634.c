//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
  char name[256];
  struct File* next;
  int data[1024];
} File;

File* head = NULL;

void createFile(char* name) {
  File* newFile = malloc(sizeof(File));
  strcpy(newFile->name, name);
  newFile->next = head;
  head = newFile;
}

void writeFile(char* name, int data) {
  File* file = head;
  while (file) {
    if (strcmp(file->name, name) == 0) {
      file->data[data] = 1;
      return;
    }
    file = file->next;
  }
  printf("Error: file not found.\n");
}

int readFile(char* name) {
  File* file = head;
  while (file) {
    if (strcmp(file->name, name) == 0) {
      return file->data[0];
    }
    file = file->next;
  }
  printf("Error: file not found.\n");
  return -1;
}

int main() {
  createFile("foo.txt");
  writeFile("foo.txt", 10);
  printf("Data in foo.txt: %d\n", readFile("foo.txt"));
  return 0;
}