//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
  char name[255];
  struct File* next;
  int size;
  char data[1000];
} File;

File* head = NULL;

void createFile(char* name, int size) {
  File* newFile = (File*)malloc(sizeof(File));
  strcpy(newFile->name, name);
  newFile->next = head;
  head = newFile;
  newFile->size = size;
  newFile->data[0] = '\0';
}

void writeFile(char* name, char* data) {
  File* file = head;
  while (file) {
    if (strcmp(file->name, name) == 0) {
      int i = 0;
      while (data[i] != '\0') {
        file->data[i] = data[i];
        i++;
      }
      file->data[i] = '\0';
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
      printf("%s\n", file->data);
      return;
    }
    file = file->next;
  }
  printf("Error: File not found.\n");
}

int main() {
  createFile("myFile.txt", 10);
  writeFile("myFile.txt", "Hello, world!");
  readFile("myFile.txt");
  return 0;
}