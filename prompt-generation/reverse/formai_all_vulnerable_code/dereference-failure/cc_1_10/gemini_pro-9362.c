//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of files and directories
#define MAX_FILES 100
#define MAX_DIRS 100

// Define the maximum length of a file or directory name
#define MAX_NAME_LEN 20

// Define the maximum number of characters in a line of text
#define MAX_LINE_LEN 100

// Define the file system structure
typedef struct {
    char name[MAX_NAME_LEN];
    int size;
    time_t timestamp;
} file_t;

typedef struct {
    char name[MAX_NAME_LEN];
    file_t files[MAX_FILES];
    int num_files;
} dir_t;

// Define the root directory
dir_t root_dir = { "root", {}, 0 };

// Function to create a new file
file_t *create_file(char *name, int size) {
    // Allocate memory for the new file
    file_t *file = malloc(sizeof(file_t));

    // Set the file's name, size, and timestamp
    strncpy(file->name, name, MAX_NAME_LEN);
    file->size = size;
    file->timestamp = time(NULL);

    // Return the new file
    return file;
}

// Function to create a new directory
dir_t *create_dir(char *name) {
    // Allocate memory for the new directory
    dir_t *dir = malloc(sizeof(dir_t));

    // Set the directory's name and number of files
    strncpy(dir->name, name, MAX_NAME_LEN);
    dir->num_files = 0;

    // Return the new directory
    return dir;
}

// Function to add a file to a directory
void add_file_to_dir(dir_t *dir, file_t *file) {
    // Add the file to the directory's list of files
    dir->files[dir->num_files++] = *file;
}

// Function to add a directory to a directory
void add_dir_to_dir(dir_t *dir, dir_t *subdir) {
    // Add the subdirectory to the directory's list of files
    dir->files[dir->num_files++] = (file_t) { .name = subdir->name, .size = 0, .timestamp = 0 };
}

// Function to print the contents of a directory
void print_dir(dir_t *dir) {
    // Print the directory's name
    printf("%s:\n", dir->name);

    // Print the directory's files
    for (int i = 0; i < dir->num_files; i++) {
        printf("  %s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

// Function to run the file system simulation
void run_simulation() {
    // Create some files and directories
    file_t *file1 = create_file("file1.txt", 100);
    file_t *file2 = create_file("file2.txt", 200);
    dir_t *dir1 = create_dir("dir1");
    dir_t *dir2 = create_dir("dir2");

    // Add the files and directories to the root directory
    add_file_to_dir(&root_dir, file1);
    add_file_to_dir(&root_dir, file2);
    add_dir_to_dir(&root_dir, dir1);
    add_dir_to_dir(&root_dir, dir2);

    // Print the contents of the root directory
    print_dir(&root_dir);
}

int main() {
    // Run the file system simulation
    run_simulation();

    return 0;
}