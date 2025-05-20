//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the file system structure
typedef struct file_system {
  char *name;
  char *path;
  int size;
  struct file_system *next;
} file_system;

// Create a new file system
file_system *new_file_system(char *name, char *path, int size) {
  file_system *new_file = malloc(sizeof(file_system));
  new_file->name = strdup(name);
  new_file->path = strdup(path);
  new_file->size = size;
  new_file->next = NULL;
  return new_file;
}

// Add a file to the file system
void add_file(file_system **head, char *name, char *path, int size) {
  file_system *new_file = new_file_system(name, path, size);
  if (*head == NULL) {
    *head = new_file;
  } else {
    file_system *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_file;
  }
}

// Print the file system
void print_file_system(file_system *head) {
  file_system *current = head;
  while (current != NULL) {
    printf("%s (%s, %d)\n", current->name, current->path, current->size);
    current = current->next;
  }
}

// Free the file system
void free_file_system(file_system *head) {
  file_system *current = head;
  while (current != NULL) {
    file_system *next = current->next;
    free(current->name);
    free(current->path);
    free(current);
    current = next;
  }
}

// Main function
int main() {
  // Create a new file system
  file_system *file_system = NULL;

  // Add some files to the file system
  add_file(&file_system, "file1.txt", "/home/user/file1.txt", 1024);
  add_file(&file_system, "file2.txt", "/home/user/file2.txt", 2048);
  add_file(&file_system, "file3.txt", "/home/user/file3.txt", 4096);

  // Print the file system
  printf("File System:\n");
  print_file_system(file_system);

  // Free the file system
  free_file_system(file_system);

  return 0;
}