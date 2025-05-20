//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our romantic file system
typedef struct {
  char *name;
  char *contents;
  int size;
} File;

// Our romantic directory
typedef struct {
  char *name;
  File **files;
  int num_files;
} Directory;

// Create a new file
File *create_file(char *name, char *contents) {
  File *file = malloc(sizeof(File));
  file->name = strdup(name);
  file->contents = strdup(contents);
  file->size = strlen(contents);
  return file;
}

// Create a new directory
Directory *create_directory(char *name) {
  Directory *directory = malloc(sizeof(Directory));
  directory->name = strdup(name);
  directory->files = malloc(sizeof(File *) * 10);
  directory->num_files = 0;
  return directory;
}

// Add a file to a directory
void add_file_to_directory(Directory *directory, File *file) {
  directory->files[directory->num_files++] = file;
}

// Print the contents of a file
void print_file(File *file) {
  printf("File: %s\n", file->name);
  printf("Contents: %s\n", file->contents);
  printf("Size: %d\n", file->size);
  printf("\n");
}

// Print the contents of a directory
void print_directory(Directory *directory) {
  printf("Directory: %s\n", directory->name);
  for (int i = 0; i < directory->num_files; i++) {
    print_file(directory->files[i]);
  }
  printf("\n");
}

// Our main function
int main() {
  // Create a new directory
  Directory *directory = create_directory("My Romantic Files");

  // Create a new file
  File *file = create_file("love.txt", "I love you more than words can say.\n");

  // Add the file to the directory
  add_file_to_directory(directory, file);

  // Print the contents of the directory
  print_directory(directory);

  // Free the memory
  free(directory->files);
  free(directory);
  free(file->name);
  free(file->contents);
  free(file);

  return 0;
}