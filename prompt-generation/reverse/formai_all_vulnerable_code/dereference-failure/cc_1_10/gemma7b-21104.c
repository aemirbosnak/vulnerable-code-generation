//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILES 1024

typedef struct File {
  char name[256];
  struct File* next;
  int data[1024];
} File;

File* head = NULL;

void createFile(char* name) {
  File* newFile = malloc(sizeof(File));
  strcpy(newFile->name, name);
  newFile->next = NULL;
  if (head == NULL) {
    head = newFile;
  } else {
    head->next = newFile;
    head = newFile;
  }
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
  printf("Error: File not found.\n");
}

int readFile(char* name) {
  File* file = head;
  while (file) {
    if (strcmp(file->name, name) == 0) {
      for (int i = 0; file->data[i] != 0; i++) {
        printf("%d ", file->data[i]);
      }
      printf("\n");
      return 0;
    }
    file = file->next;
  }
  printf("Error: File not found.\n");
  return -1;
}

int main() {
  createFile("foo.txt");
  writeFile("foo.txt", 10);
  writeFile("foo.txt", 20);
  readFile("foo.txt");
  return 0;
}