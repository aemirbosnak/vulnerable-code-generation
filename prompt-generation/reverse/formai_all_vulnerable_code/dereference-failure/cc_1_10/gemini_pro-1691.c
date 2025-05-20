//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

// Define the maximum number of files and directories that can be stored in the file system.
#define MAX_FILES 100
#define MAX_DIRS 100

// Define the maximum length of a file or directory name.
#define MAX_NAME_LEN 256

// Define the structure of a file or directory.
typedef struct file_dir {
  char name[MAX_NAME_LEN];
  int type; // 0 for file, 1 for directory
  int size; // Size in bytes for files, number of files for directories
  struct file_dir *children[MAX_FILES]; // Array of pointers to child files/directories
  int num_children; // Number of child files/directories
} file_dir;

// Define the root directory of the file system.
file_dir *root_dir;

// Function to create a new file or directory.
file_dir *create_file_dir(const char *name, int type, int size) {
  // Allocate memory for the new file or directory.
  file_dir *new_file_dir = malloc(sizeof(file_dir));
  
  // Initialize the new file or directory.
  strcpy(new_file_dir->name, name);
  new_file_dir->type = type;
  new_file_dir->size = size;
  new_file_dir->num_children = 0;
  
  // Return the new file or directory.
  return new_file_dir;
}

// Function to add a new file or directory to a parent directory.
void add_file_dir(file_dir *parent_dir, file_dir *new_file_dir) {
  // Add the new file or directory to the parent directory's array of children.
  parent_dir->children[parent_dir->num_children] = new_file_dir;
  
  // Increment the parent directory's number of children.
  parent_dir->num_children++;
}

// Function to print the contents of a directory.
void print_dir(file_dir *dir) {
  // Print the directory's name.
  printf("%s:\n", dir->name);
  
  // Print the directory's contents.
  for (int i = 0; i < dir->num_children; i++) {
    printf("  %s\n", dir->children[i]->name);
  }
}

// Function to find a file or directory by name.
file_dir *find_file_dir(file_dir *dir, const char *name) {
  // Iterate over the directory's children.
  for (int i = 0; i < dir->num_children; i++) {
    // If the child's name matches the given name, return the child.
    if (strcmp(dir->children[i]->name, name) == 0) {
      return dir->children[i];
    }
  }
  
  // If the file or directory was not found, return NULL.
  return NULL;
}

// Function to delete a file or directory.
void delete_file_dir(file_dir *dir, const char *name) {
  // Find the file or directory to delete.
  file_dir *file_dir_to_delete = find_file_dir(dir, name);
  
  // If the file or directory was not found, return.
  if (file_dir_to_delete == NULL) {
    return;
  }
  
  // Remove the file or directory from its parent directory's array of children.
  for (int i = 0; i < dir->num_children; i++) {
    if (dir->children[i] == file_dir_to_delete) {
      dir->children[i] = dir->children[dir->num_children - 1];
      dir->num_children--;
      break;
    }
  }
  
  // Free the memory allocated to the file or directory.
  free(file_dir_to_delete);
}

// Function to create a new file system.
file_dir *create_file_system() {
  // Allocate memory for the root directory.
  root_dir = malloc(sizeof(file_dir));
  
  // Initialize the root directory.
  strcpy(root_dir->name, "/");
  root_dir->type = 1; // Directory
  root_dir->size = 0;
  root_dir->num_children = 0;
  
  // Return the root directory.
  return root_dir;
}

// Function to mount a file system.
void mount_file_system(file_dir *file_system) {
  // Set the current working directory to the root directory of the file system.
  chdir(file_system->name);
}

// Function to unmount a file system.
void unmount_file_system() {
  // Set the current working directory to the parent directory of the file system.
  chdir("..");
}

// Main function.
int main() {
  // Create a new file system.
  file_dir *file_system = create_file_system();
  
  // Mount the file system.
  mount_file_system(file_system);
  
  // Create a new directory named "bin".
  file_dir *bin_dir = create_file_dir("bin", 1, 0);
  add_file_dir(root_dir, bin_dir);
  
  // Create a new file named "hello.txt" in the "bin" directory.
  file_dir *hello_txt_file = create_file_dir("hello.txt", 0, 10);
  add_file_dir(bin_dir, hello_txt_file);
  
  // Print the contents of the root directory.
  print_dir(root_dir);
  
  // Unmount the file system.
  unmount_file_system();
  
  return 0;
}