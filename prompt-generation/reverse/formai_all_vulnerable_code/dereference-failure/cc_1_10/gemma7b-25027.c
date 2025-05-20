//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the file system structure
typedef struct file_system {
    char **directories;
    int num_dirs;
    char **files;
    int num_files;
} file_system;

// Create a new file system
file_system *create_file_system(int num_dirs, int num_files) {
    file_system *fs = malloc(sizeof(file_system));
    fs->directories = malloc(num_dirs * sizeof(char *));
    fs->num_dirs = num_dirs;
    fs->files = malloc(num_files * sizeof(char *));
    fs->num_files = num_files;
    return fs;
}

// List all files in a directory
void list_files(file_system *fs, char *dir) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i], dir) == 0) {
            printf("%s\n", fs->files[i]);
        }
    }
}

// Add a new file to a directory
void add_file(file_system *fs, char *dir, char *file) {
    for (int i = 0; i < fs->num_dirs; i++) {
        if (strcmp(fs->directories[i], dir) == 0) {
            fs->files[fs->num_files++] = file;
            return;
        }
    }

    // Error: directory not found
    return;
}

int main() {
    // Create a new file system
    file_system *fs = create_file_system(5, 10);

    // Add some files to the file system
    add_file(fs, "dir1", "file1.txt");
    add_file(fs, "dir2", "file2.txt");
    add_file(fs, "dir1", "file3.txt");

    // List all files in directory "dir1"
    list_files(fs, "dir1");

    return 0;
}