//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct DirNode {
  char name[256];
  struct DirNode **children;
  struct FileNode **files;
} DirNode;

typedef struct FileNode {
  char name[256];
  int size;
  struct FileNode *next;
} FileNode;

DirNode *rootDir;

void createDir(char *name) {
  DirNode *newNode = malloc(sizeof(DirNode));
  strcpy(newNode->name, name);
  newNode->children = NULL;
  newNode->files = NULL;

  if (rootDir == NULL) {
    rootDir = newNode;
  } else {
    DirNode *current = rootDir;
    while (current->children) {
      current = current->children;
    }
    current->children = newNode;
  }
}

void createFile(char *name, int size) {
  FileNode *newNode = malloc(sizeof(FileNode));
  strcpy(newNode->name, name);
  newNode->size = size;
  newNode->next = NULL;

  DirNode *current = rootDir;
  while (current->children) {
    current = current->children;
  }
  current->files = newNode;
}

void listFiles(DirNode *node) {
  printf("%s:\n", node->name);
  for (FileNode *file = node->files; file; file = file->next) {
    printf("  %s (%d bytes)\n", file->name, file->size);
  }
  for (DirNode *child = node->children; child; child = child->children) {
    listFiles(child);
  }
}

int main() {
  createDir("home");
  createDir("home/docs");
  createDir("home/photos");
  createDir("home/music");

  createFile("home/docs/test.txt", 100);
  createFile("home/photos/image.jpg", 200);
  createFile("home/music/song.mp3", 300);

  listFiles(rootDir);

  return 0;
}