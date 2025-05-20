//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
  char name[255];
  struct File* next;
  FILE* fp;
} File;

File* head = NULL;

void createFile(char* name) {
  File* newFile = malloc(sizeof(File));
  strcpy(newFile->name, name);
  newFile->next = NULL;
  newFile->fp = fopen(name, "w");
  if (head == NULL) {
    head = newFile;
  } else {
    head->next = newFile;
  }
}

void listFiles() {
  File* currentFile = head;
  while (currentFile) {
    printf("%s\n", currentFile->name);
    currentFile = currentFile->next;
  }
}

void openFile(char* name) {
  File* currentFile = head;
  while (currentFile) {
    if (strcmp(currentFile->name, name) == 0) {
      currentFile->fp = fopen(name, "r");
      break;
    }
    currentFile = currentFile->next;
  }
}

void closeFile(char* name) {
  File* currentFile = head;
  while (currentFile) {
    if (strcmp(currentFile->name, name) == 0) {
      fclose(currentFile->fp);
      break;
    }
    currentFile = currentFile->next;
  }
}

int main() {
  createFile("test.txt");
  createFile("another.txt");
  listFiles();
  openFile("test.txt");
  closeFile("test.txt");
  listFiles();
  return 0;
}