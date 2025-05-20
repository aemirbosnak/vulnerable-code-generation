//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a file system
#define MAX_FILESYSTEM_SIZE 1024

// Define the maximum number of files in a file system
#define MAX_FILES 10

// Define the maximum size of a file
#define MAX_FILE_SIZE 1024

// Define the structure of a file
typedef struct {
  char name[32];
  int size;
  int start_block;
} file_t;

// Define the structure of a file system
typedef struct {
  file_t files[MAX_FILES];
  int num_files;
  int free_space;
  int start_block;
} file_system_t;

// Create a new file system
file_system_t *create_file_system() {
  file_system_t *file_system = malloc(sizeof(file_system_t));
  file_system->num_files = 0;
  file_system->free_space = MAX_FILESYSTEM_SIZE;
  file_system->start_block = 0;
  return file_system;
}

// Destroy a file system
void destroy_file_system(file_system_t *file_system) {
  free(file_system);
}

// Add a file to a file system
int add_file(file_system_t *file_system, file_t *file) {
  if (file_system->num_files >= MAX_FILES) {
    return -1;
  }

  if (file_system->free_space < file->size) {
    return -1;
  }

  file_system->files[file_system->num_files] = *file;
  file_system->num_files++;
  file_system->free_space -= file->size;
  file_system->start_block += file->size;
  return 0;
}

// Delete a file from a file system
int delete_file(file_system_t *file_system, char *name) {
  int i;

  for (i = 0; i < file_system->num_files; i++) {
    if (strcmp(file_system->files[i].name, name) == 0) {
      break;
    }
  }

  if (i == file_system->num_files) {
    return -1;
  }

  file_system->num_files--;
  file_system->free_space += file_system->files[i].size;
  file_system->start_block -= file_system->files[i].size;

  for (; i < file_system->num_files; i++) {
    file_system->files[i] = file_system->files[i + 1];
  }

  return 0;
}

// Print the contents of a file system
void print_file_system(file_system_t *file_system) {
  int i;

  printf("File System:\n");
  printf("Number of files: %d\n", file_system->num_files);
  printf("Free space: %d\n", file_system->free_space);
  printf("Start block: %d\n", file_system->start_block);
  printf("\nFiles:\n");

  for (i = 0; i < file_system->num_files; i++) {
    printf("  %s (%d bytes)\n", file_system->files[i].name, file_system->files[i].size);
  }

  printf("\n");
}

// Main function
int main() {
  file_system_t *file_system;
  file_t file;

  // Create a new file system
  file_system = create_file_system();

  // Add some files to the file system
  strcpy(file.name, "file1.txt");
  file.size = 1024;
  add_file(file_system, &file);

  strcpy(file.name, "file2.txt");
  file.size = 512;
  add_file(file_system, &file);

  strcpy(file.name, "file3.txt");
  file.size = 256;
  add_file(file_system, &file);

  // Print the contents of the file system
  print_file_system(file_system);

  // Delete a file from the file system
  delete_file(file_system, "file2.txt");

  // Print the contents of the file system
  print_file_system(file_system);

  // Destroy the file system
  destroy_file_system(file_system);

  return 0;
}