//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 255

typedef struct File {
  char name[MAX_FILE_NAME_LENGTH];
  int data[MAX_FILES];
  struct File* next;
} File;

File* head = NULL;

void createFile(char* name, int data) {
  File* newFile = malloc(sizeof(File));

  strcpy(newFile->name, name);
  newFile->data[0] = data;
  newFile->next = NULL;

  if (head == NULL) {
    head = newFile;
  } else {
    head->next = newFile;
    head = newFile;
  }
}

void readData(char* name) {
  File* currentFile = head;

  while (currentFile) {
    if (strcmp(currentFile->name, name) == 0) {
      printf("Data: %d\n", currentFile->data[0]);
      break;
    }
    currentFile = currentFile->next;
  }

  if (currentFile == NULL) {
    printf("File not found.\n");
  }
}

int main() {
  // Create a few files
  createFile("my_file.txt", 10);
  createFile("another_file.txt", 20);

  // Read data from a file
  readData("my_file.txt");

  // Read data from a non-existent file
  readData("non_existent_file.txt");

  return 0;
}