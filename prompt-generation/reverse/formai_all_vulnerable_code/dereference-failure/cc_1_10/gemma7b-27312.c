//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
  char name[20];
  int data[1024];
  struct File* next;
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
      break;
    }
    file = file->next;
  }
  if (file == NULL) {
    printf("Error: File not found.\n");
  }
}

void readFile(char* name) {
  File* file = head;
  while (file) {
    if (strcmp(file->name, name) == 0) {
      for (int i = 0; file->data[i] != 0; i++) {
        printf("%d ", file->data[i]);
      }
      break;
    }
    file = file->next;
  }
  if (file == NULL) {
    printf("Error: File not found.\n");
  }
}

int main() {
  createFile("foo.txt");
  writeFile("foo.txt", 10);
  writeFile("foo.txt", 20);
  readFile("foo.txt");
  return 0;
}