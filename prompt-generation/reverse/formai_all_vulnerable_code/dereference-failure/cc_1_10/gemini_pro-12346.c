//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a file name
#define MAX_FILE_NAME_LENGTH 256

// Define the maximum number of files that can be stored in the file system
#define MAX_FILES 100

// Define the maximum size of a file
#define MAX_FILE_SIZE 1024

// Define the structure of a file
typedef struct {
  char name[MAX_FILE_NAME_LENGTH];
  int size;
  char data[MAX_FILE_SIZE];
} File;

// Define the structure of the file system
typedef struct {
  File files[MAX_FILES];
  int num_files;
} FileSystem;

// Create a new file system
FileSystem *create_file_system() {
  FileSystem *fs = malloc(sizeof(FileSystem));
  fs->num_files = 0;
  return fs;
}

// Destroy a file system
void destroy_file_system(FileSystem *fs) {
  free(fs);
}

// Create a new file
File *create_file(char *name, int size) {
  File *file = malloc(sizeof(File));
  strncpy(file->name, name, MAX_FILE_NAME_LENGTH);
  file->size = size;
  return file;
}

// Destroy a file
void destroy_file(File *file) {
  free(file);
}

// Add a file to the file system
int add_file(FileSystem *fs, File *file) {
  if (fs->num_files == MAX_FILES) {
    return -1;
  }
  fs->files[fs->num_files++] = *file;
  return 0;
}

// Get a file from the file system
File *get_file(FileSystem *fs, char *name) {
  for (int i = 0; i < fs->num_files; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      return &fs->files[i];
    }
  }
  return NULL;
}

// Delete a file from the file system
int delete_file(FileSystem *fs, char *name) {
  for (int i = 0; i < fs->num_files; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      for (int j = i + 1; j < fs->num_files; j++) {
        fs->files[j - 1] = fs->files[j];
      }
      fs->num_files--;
      return 0;
    }
  }
  return -1;
}

// List the files in the file system
void list_files(FileSystem *fs) {
  for (int i = 0; i < fs->num_files; i++) {
    printf("%s\n", fs->files[i].name);
  }
}

// Main function
int main() {
  // Create a new file system
  FileSystem *fs = create_file_system();

  // Add some files to the file system
  File *file1 = create_file("file1.txt", 1024);
  add_file(fs, file1);
  File *file2 = create_file("file2.txt", 512);
  add_file(fs, file2);
  File *file3 = create_file("file3.txt", 256);
  add_file(fs, file3);

  // List the files in the file system
  list_files(fs);

  // Get a file from the file system
  File *file = get_file(fs, "file2.txt");
  if (file != NULL) {
    printf("File size: %d\n", file->size);
  }

  // Delete a file from the file system
  delete_file(fs, "file3.txt");

  // List the files in the file system
  list_files(fs);

  // Destroy the file system
  destroy_file_system(fs);

  return 0;
}