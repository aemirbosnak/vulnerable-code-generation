//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the file system structure
typedef struct File {
    char* name;
    int size;
    struct File* next;
} File;

// Define the directory structure
typedef struct Directory {
    char* name;
    struct File* files;
    struct Directory* parent;
    struct Directory* next;
} Directory;

// Create a new file
File* new_file(char* name, int size) {
    File* file = (File*)malloc(sizeof(File));
    file->name = strdup(name);
    file->size = size;
    file->next = NULL;
    return file;
}

// Create a new directory
Directory* new_directory(char* name) {
    Directory* dir = (Directory*)malloc(sizeof(Directory));
    dir->name = strdup(name);
    dir->files = NULL;
    dir->parent = NULL;
    dir->next = NULL;
    return dir;
}

// Add a file to a directory
void add_file(Directory* dir, File* file) {
    if (dir->files == NULL) {
        dir->files = file;
    } else {
        File* curr = dir->files;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = file;
    }
}

// Add a directory to a directory
void add_directory(Directory* dir, Directory* new_dir) {
    if (dir->next == NULL) {
        dir->next = new_dir;
    } else {
        Directory* curr = dir->next;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_dir;
    }
}

// Print the contents of a directory
void print_directory(Directory* dir) {
    printf("Directory: %s\n", dir->name);
    File* file = dir->files;
    while (file != NULL) {
        printf("  File: %s (%d bytes)\n", file->name, file->size);
        file = file->next;
    }
    Directory* sub_dir = dir->next;
    while (sub_dir != NULL) {
        printf("  Directory: %s\n", sub_dir->name);
        sub_dir = sub_dir->next;
    }
}

// Main function
int main() {
    // Create the root directory
    Directory* root = new_directory("/");

    // Add some files and directories to the root directory
    add_file(root, new_file("file1.txt", 100));
    add_file(root, new_file("file2.txt", 200));
    add_directory(root, new_directory("sub_dir1"));
    add_directory(root, new_directory("sub_dir2"));

    // Add some files and directories to the subdirectories
    add_file(root->next, new_file("file3.txt", 300));
    add_file(root->next->next, new_file("file4.txt", 400));

    // Print the contents of the root directory
    print_directory(root);

    return 0;
}