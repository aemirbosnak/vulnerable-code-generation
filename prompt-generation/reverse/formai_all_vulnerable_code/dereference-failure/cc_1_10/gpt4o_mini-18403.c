//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of files and directories
#define MAX_FILES 100
#define MAX_DIRS 50
#define MAX_NAME_LENGTH 50

// Structure to represent a file
typedef struct File {
    char name[MAX_NAME_LENGTH];
    int size;
} File;

// Structure to represent a directory
typedef struct Directory {
    char name[MAX_NAME_LENGTH];
    struct Directory *subdirectories[MAX_DIRS];
    File *files[MAX_FILES];
    int file_count;
    int dir_count;
} Directory;

// Function declarations
Directory *create_directory(const char *name);
File *create_file(const char *name, int size);
void add_file_to_directory(Directory *dir, File *file);
void add_subdirectory(Directory *parent, Directory *child);
void print_directory_structure(Directory *dir, int level);
void free_directory(Directory *dir);

// Function to create a new directory
Directory *create_directory(const char *name) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    strcpy(dir->name, name);
    dir->file_count = 0;
    dir->dir_count = 0;
    return dir;
}

// Function to create a new file
File *create_file(const char *name, int size) {
    File *file = (File *)malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    return file;
}

// Function to add a file to a directory
void add_file_to_directory(Directory *dir, File *file) {
    if (dir->file_count < MAX_FILES) {
        dir->files[dir->file_count++] = file;
    } else {
        printf("Max file limit reached in directory: %s\n", dir->name);
    }
}

// Function to add a subdirectory to a directory
void add_subdirectory(Directory *parent, Directory *child) {
    if (parent->dir_count < MAX_DIRS) {
        parent->subdirectories[parent->dir_count++] = child;
    } else {
        printf("Max directory limit reached in directory: %s\n", parent->name);
    }
}

// Function to print directory structure recursively
void print_directory_structure(Directory *dir, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("Directory: %s\n", dir->name);
    
    for (int i = 0; i < dir->file_count; i++) {
        for (int j = 0; j < level + 1; j++) {
            printf("  ");
        }
        printf("File: %s (Size: %d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }

    for (int i = 0; i < dir->dir_count; i++) {
        print_directory_structure(dir->subdirectories[i], level + 1);
    }
}

// Function to free the allocated memory of a directory
void free_directory(Directory *dir) {
    for (int i = 0; i < dir->file_count; i++) {
        free(dir->files[i]);
    }
    for (int i = 0; i < dir->dir_count; i++) {
        free_directory(dir->subdirectories[i]);
    }
    free(dir);
}

// Main function to demonstrate the file system simulation
int main() {
    Directory *root = create_directory("root");
    
    Directory *home = create_directory("home");
    Directory *user1 = create_directory("user1");
    Directory *user2 = create_directory("user2");

    File *file1 = create_file("file1.txt", 1500);
    File *file2 = create_file("file2.doc", 3000);
    File *file3 = create_file("file3.jpg", 2000);
    File *file4 = create_file("file4.txt", 1200);
    
    add_file_to_directory(user1, file1);
    add_file_to_directory(user1, file2);
    add_file_to_directory(user2, file3);
    add_file_to_directory(user2, file4);
    
    add_subdirectory(home, user1);
    add_subdirectory(home, user2);
    add_subdirectory(root, home);

    // Print the directory structure
    print_directory_structure(root, 0);

    // Free the allocated memory
    free_directory(root);

    return 0;
}