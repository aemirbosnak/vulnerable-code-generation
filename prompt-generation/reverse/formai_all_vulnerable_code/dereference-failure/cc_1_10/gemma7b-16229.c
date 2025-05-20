//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct Node {
  char name[MAX_FILE_NAME_LENGTH];
  struct Node* next;
} Node;

typedef struct FileSystem {
  Node* root;
  int numFiles;
} FileSystem;

void createFileSystem(FileSystem* fs) {
  fs->root = NULL;
  fs->numFiles = 0;
}

void addFile(FileSystem* fs, char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (fs->root == NULL) {
    fs->root = newNode;
  } else {
    Node* current = fs->root;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  fs->numFiles++;
}

void listFiles(FileSystem* fs) {
  Node* current = fs->root;
  while (current) {
    printf("%s\n", current->name);
    current = current->next;
  }
}

int main() {
  FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
  createFileSystem(fs);

  // Add some files
  addFile(fs, "my_file.txt");
  addFile(fs, "another_file.doc");
  addFile(fs, "directory.dir");

  // List all files
  listFiles(fs);

  // Free memory
  free(fs);

  return 0;
}