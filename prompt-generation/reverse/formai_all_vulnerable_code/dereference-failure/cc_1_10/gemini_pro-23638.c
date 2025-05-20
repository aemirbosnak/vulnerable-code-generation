//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
// A Dennis Ritchie-style C File System Simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct File {
  char *name;
  int size;
  struct File *next;
} File;

// Directory structure
typedef struct Directory {
  char *name;
  struct File *files;
  struct Directory *parent;
  struct Directory *next;
} Directory;

// Root directory
Directory *root = NULL;

// Create a new file
File *create_file(char *name, int size) {
  File *file = malloc(sizeof(File));
  file->name = strdup(name);
  file->size = size;
  file->next = NULL;
  return file;
}

// Create a new directory
Directory *create_directory(char *name) {
  Directory *dir = malloc(sizeof(Directory));
  dir->name = strdup(name);
  dir->files = NULL;
  dir->parent = NULL;
  dir->next = NULL;
  return dir;
}

// Add a file to a directory
void add_file_to_directory(Directory *dir, File *file) {
  file->next = dir->files;
  dir->files = file;
}

// Add a directory to a directory
void add_directory_to_directory(Directory *dir, Directory *child) {
  child->parent = dir;
  child->next = dir->next;
  dir->next = child;
}

// Print the file system
void print_file_system(Directory *dir) {
  printf("%s\n", dir->name);
  File *file = dir->files;
  while (file != NULL) {
    printf("  %s (%d bytes)\n", file->name, file->size);
    file = file->next;
  }
  Directory *child = dir->next;
  while (child != NULL) {
    print_file_system(child);
    child = child->next;
  }
}

// Free the file system
void free_file_system(Directory *dir) {
  File *file = dir->files;
  while (file != NULL) {
    File *next = file->next;
    free(file->name);
    free(file);
    file = next;
  }
  Directory *child = dir->next;
  while (child != NULL) {
    Directory *next = child->next;
    free_file_system(child);
    free(child->name);
    free(child);
    child = next;
  }
  free(dir->name);
  free(dir);
}

// Main function
int main() {
  // Create the root directory
  root = create_directory("/");

  // Add some files and directories to the root directory
  add_file_to_directory(root, create_file("file1.txt", 100));
  add_file_to_directory(root, create_file("file2.txt", 200));
  add_directory_to_directory(root, create_directory("dir1"));
  add_directory_to_directory(root, create_directory("dir2"));

  // Add some files and directories to the dir1 directory
  Directory *dir1 = root->next;
  add_file_to_directory(dir1, create_file("file3.txt", 300));
  add_directory_to_directory(dir1, create_directory("dir11"));

  // Print the file system
  print_file_system(root);

  // Free the file system
  free_file_system(root);

  return 0;
}