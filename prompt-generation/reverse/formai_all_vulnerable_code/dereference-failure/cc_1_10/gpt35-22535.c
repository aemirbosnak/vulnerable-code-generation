//FormAI DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int size;
  char content[50];
} File;

typedef struct {
  char name[20];
  int size;
  File *files[10];
} Directory;

Directory *root;

void initialize() {
  root = (Directory*) malloc(sizeof(Directory));
  strcpy(root->name, "/");
  root->size = 0;
}

void list_files(Directory *dir) {
  printf("\nFiles in directory %s:\n", dir->name);
  for (int i = 0; i < dir->size; i++) {
    printf("\t- %s\n", dir->files[i]->name);
  }
}

void create_file(Directory *dir, char *name) {
  File *file = (File*) malloc(sizeof(File));
  strcpy(file->name, name);
  file->size = 0;
  strcpy(file->content, "");

  if (dir->size == 10) {
    printf("Directory is full!\n");
    return;
  }

  for (int i = 0; i < dir->size; i++) {
    if (strcmp(dir->files[i]->name, name) == 0) {
      printf("File already exists!\n");
      return;
    }
  }

  dir->files[dir->size++] = file;
  printf("File %s created in directory %s.\n", name, dir->name);
}

void delete_file(Directory *dir, char *name) {
  for (int i = 0; i < dir->size; i++) {
    if (strcmp(dir->files[i]->name, name) == 0) {
      free(dir->files[i]);
      dir->size--;
      for (int j = i; j < dir->size; j++) {
        dir->files[j] = dir->files[j+1];
      }
      printf("File %s deleted from directory %s.\n", name, dir->name);
      return;
    }
  }
  printf("File not found!\n");
}

int main() {
  initialize();

  printf("\n\nWelcome to the C File System Simulation!\n");

  while (1) {
    printf("\n\nType a command (e.g. 'ls', 'touch', 'rm', 'exit'):\n");

    char command[10], arg[20];
    scanf("%s", command);

    if (strcmp(command, "ls") == 0) {
      list_files(root);
    }

    else if (strcmp(command, "touch") == 0) {
      scanf("%s", arg);
      create_file(root, arg);
    }

    else if (strcmp(command, "rm") == 0) {
      scanf("%s", arg);
      delete_file(root, arg);
    }

    else if (strcmp(command, "exit") == 0) {
      printf("Goodbye!\n");
      exit(0);
    }

    else {
      printf("Invalid command!\n");
    }
  }

  return 0;
}