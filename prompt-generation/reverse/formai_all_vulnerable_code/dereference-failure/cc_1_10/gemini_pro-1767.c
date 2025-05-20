//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the file system structure
typedef struct {
  char *name;
  int size;
  char *data;
} File;

// Define the file system
File *files[100];
int num_files = 0;

// Create a new file
File *create_file(char *name, int size) {
  // Allocate memory for the file
  File *file = malloc(sizeof(File));

  // Set the file's name, size, and data
  file->name = strdup(name);
  file->size = size;
  file->data = malloc(size);

  // Add the file to the file system
  files[num_files] = file;
  num_files++;

  return file;
}

// Open a file
File *open_file(char *name) {
  // Find the file in the file system
  for (int i = 0; i < num_files; i++) {
    if (strcmp(files[i]->name, name) == 0) {
      return files[i];
    }
  }

  // File not found
  return NULL;
}

// Read from a file
int read_file(File *file, char *buffer, int size) {
  // Copy the file's data to the buffer
  memcpy(buffer, file->data, size);

  return size;
}

// Write to a file
int write_file(File *file, char *buffer, int size) {
  // Copy the buffer's data to the file
  memcpy(file->data, buffer, size);

  return size;
}

// Close a file
void close_file(File *file) {
  // Free the memory allocated for the file
  free(file->name);
  free(file->data);
  free(file);
}

// Delete a file
void delete_file(char *name) {
  // Find the file in the file system
  for (int i = 0; i < num_files; i++) {
    if (strcmp(files[i]->name, name) == 0) {
      // Free the memory allocated for the file
      free(files[i]->name);
      free(files[i]->data);
      free(files[i]);

      // Remove the file from the file system
      for (int j = i; j < num_files - 1; j++) {
        files[j] = files[j + 1];
      }

      num_files--;

      return;
    }
  }

  // File not found
}

// Print the file system
void print_file_system() {
  for (int i = 0; i < num_files; i++) {
    printf("File: %s, Size: %d, Data: %s\n", files[i]->name, files[i]->size, files[i]->data);
  }
}

// Main function
int main() {
  // Create a new file
  File *file1 = create_file("file1.txt", 100);

  // Open the file
  File *file2 = open_file("file1.txt");

  // Read from the file
  char buffer[100];
  read_file(file2, buffer, 100);

  // Write to the file
  write_file(file2, "Hello, world!", 12);

  // Close the file
  close_file(file2);

  // Delete the file
  delete_file("file1.txt");

  // Print the file system
  print_file_system();

  return 0;
}