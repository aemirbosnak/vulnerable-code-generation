//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 5
#define MAX_FILE_SIZE 10

typedef struct Directory {
  char name[MAX_DIR_SIZE];
  struct Directory* nextDir;
  struct File* files;
} Directory;

typedef struct File {
  char name[MAX_FILE_SIZE];
  int size;
  struct File* nextFile;
  struct Directory* dir;
} File;

Directory* createDir(char* name) {
  Directory* newDir = malloc(sizeof(Directory));
  strcpy(newDir->name, name);
  newDir->nextDir = NULL;
  newDir->files = NULL;
  return newDir;
}

File* createFile(char* name, int size) {
  File* newFile = malloc(sizeof(File));
  strcpy(newFile->name, name);
  newFile->size = size;
  newFile->nextFile = NULL;
  newFile->dir = NULL;
  return newFile;
}

void listDir(Directory* dir) {
  printf("%s:\n", dir->name);
  for (File* file = dir->files; file; file = file->nextFile) {
    printf("%s (%d bytes)\n", file->name, file->size);
  }
}

void main() {
  Directory* root = createDir("Root");
  Directory* home = createDir("Home");
  Directory* games = createDir("Games");
  Directory* documents = createDir("Documents");

  File* myDocument = createFile("My Document.txt", 100);
  File* saveGame = createFile("Save Game.bin", 200);

  listDir(root);
  listDir(home);
  listDir(games);
  listDir(documents);

  printf("File: %s, Size: %d bytes\n", myDocument->name, myDocument->size);
  printf("File: %s, Size: %d bytes\n", saveGame->name, saveGame->size);
}