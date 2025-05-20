//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_BUFFER_SIZE 256

typedef struct File {
  char name[MAX_FILES];
  struct File* next;
  int size;
  char data[MAX_BUFFER_SIZE];
} File;

File* head = NULL;

void createFile(char* name, int size) {
  File* newFile = malloc(sizeof(File));
  strcpy(newFile->name, name);
  newFile->next = head;
  head = newFile;
  newFile->size = size;
  memset(newFile->data, 0, MAX_BUFFER_SIZE);
}

void writeFile(char* name, char* data, int dataSize) {
  File* file = head;
  while (file) {
    if (strcmp(file->name, name) == 0) {
      int minSize = file->size;
      if (dataSize > minSize) {
        file->size = dataSize;
        FILE* f = fopen(name, "w");
        fwrite(data, dataSize, 1, f);
        fclose(f);
      } else {
        memcpy(file->data, data, dataSize);
      }
      return;
    }
    file = file->next;
  }
  printf("Error: File not found.\n");
}

void readFile(char* name) {
  File* file = head;
  while (file) {
    if (strcmp(file->name, name) == 0) {
      printf("File contents:\n");
      printf("%s\n", file->data);
      return;
    }
    file = file->next;
  }
  printf("Error: File not found.\n");
}

int main() {
  createFile("test.txt", 10);
  writeFile("test.txt", "Hello, world!", 13);
  readFile("test.txt");
  writeFile("test.txt", "Goodbye, world!", 16);
  readFile("test.txt");
  return 0;
}