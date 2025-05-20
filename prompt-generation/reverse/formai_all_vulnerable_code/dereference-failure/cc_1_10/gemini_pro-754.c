//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct {
  char name[32];        // File name
  int size;             // File size in bytes
  char data[1024];      // File data
  struct file_system *next; // Pointer to the next file in the file system
} file_system;

// Create a new file system
file_system *create_file_system() {
  file_system *fs = (file_system *)malloc(sizeof(file_system));
  fs->next = NULL;
  return fs;
}

// Add a file to the file system
void add_file(file_system *fs, char *name, int size, char *data) {
  file_system *new_file = (file_system *)malloc(sizeof(file_system));
  strcpy(new_file->name, name);
  new_file->size = size;
  strcpy(new_file->data, data);
  new_file->next = fs->next;
  fs->next = new_file;
}

// Delete a file from the file system
void delete_file(file_system *fs, char *name) {
  file_system *current = fs;
  file_system *previous = NULL;
  while (current != NULL && strcmp(current->name, name) != 0) {
    previous = current;
    current = current->next;
  }

  if (current != NULL) {
    if (previous == NULL) {
      fs->next = current->next;
    } else {
      previous->next = current->next;
    }
    free(current);
  }
}

// Print the file system
void print_file_system(file_system *fs) {
  file_system *current = fs->next;
  while (current != NULL) {
    printf("%s (%d bytes)\n", current->name, current->size);
    current = current->next;
  }
}

// Main function
int main() {
  // Create a new file system
  file_system *fs = create_file_system();

  // Add some files to the file system
  add_file(fs, "file1.txt", 100, "This is a test file.");
  add_file(fs, "file2.txt", 200, "This is another test file.");
  add_file(fs, "file3.txt", 300, "This is the last test file.");

  // Print the file system
  print_file_system(fs);

  // Delete a file from the file system
  delete_file(fs, "file2.txt");

  // Print the file system again
  print_file_system(fs);

  return 0;
}