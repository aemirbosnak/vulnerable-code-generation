//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 255

typedef struct File {
  char name[MAX_FILE_NAME_LENGTH];
  struct File* next;
  FILE* file;
} File;

File* head = NULL;

void createFile(char* name) {
  File* newFile = (File*)malloc(sizeof(File));
  strcpy(newFile->name, name);
  newFile->next = NULL;
  newFile->file = NULL;

  if (head == NULL) {
    head = newFile;
  } else {
    head->next = newFile;
  }
}

void openFile(char* name) {
  File* file = head;

  while (file) {
    if (strcmp(file->name, name) == 0) {
      file->file = fopen(file->name, "r");
      break;
    }
    file = file->next;
  }

  if (file->file == NULL) {
    printf("Error opening file: %s\n", name);
  }
}

void closeFile(char* name) {
  File* file = head;

  while (file) {
    if (strcmp(file->name, name) == 0) {
      fclose(file->file);
      break;
    }
    file = file->next;
  }

  if (file->file == NULL) {
    printf("Error closing file: %s\n", name);
  }
}

int main() {
  createFile("poem.txt");
  openFile("poem.txt");
  closeFile("poem.txt");

  return 0;
}