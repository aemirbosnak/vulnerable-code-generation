//FormAI DATASET v1.0 Category: File system simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our surrealist style file system
#define FILE_EXTENSION ".dream"

// Define our surrealist style directory structure
typedef struct surreal_directory {
  char *name;
  struct surreal_directory **children;
  struct surreal_directory *parent;
  int num_children;
  int max_children;
} surreal_directory;

surreal_directory *init_directory(char *name) {
  surreal_directory *dir = malloc(sizeof(surreal_directory));
  dir->name = malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(dir->name, name);
  dir->children = malloc(sizeof(surreal_directory *) * 10);
  dir->parent = NULL;
  dir->num_children = 0;
  dir->max_children = 10;
  return dir;
}

void list_directory(surreal_directory *dir) {
  printf("Listing directory: %s\n", dir->name);
  for(int i = 0; i < dir->num_children; i++) {
    printf("%s\n", dir->children[i]->name);
  }
}

void create_file(surreal_directory *dir, char *name) {
  printf("Creating file: %s%s\n", name, FILE_EXTENSION);
}

void delete_file(surreal_directory *dir, char *name) {
  printf("Deleting file: %s%s\n", name, FILE_EXTENSION);
}

void create_directory(surreal_directory *dir, char *name) {
  printf("Creating directory: %s\n", name);
}

void delete_directory(surreal_directory *dir, char *name) {
  printf("Deleting directory: %s\n", name);
}

int main() {
  surreal_directory *root = init_directory("surreal_root");
  create_file(root, "dream1");
  create_file(root, "dream2");
  list_directory(root);
  delete_file(root, "dream1");
  create_directory(root, "subdir");
  list_directory(root);
  delete_directory(root, "subdir");
  delete_file(root, "dream2");
  return 0;
}