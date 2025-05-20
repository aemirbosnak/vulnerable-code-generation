//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a file
#define MAX_FILE_SIZE 1024

// Define the maximum number of files in a directory
#define MAX_FILES_IN_DIR 10

// Define the maximum number of levels in a file system
#define MAX_LEVELS 5

// Define the root directory
struct directory *root_dir;

// Define a file
struct file {
    char name[256];
    int size;
    char data[MAX_FILE_SIZE];
};

// Define a directory
struct directory {
    char name[256];
    struct directory *parent;
    struct directory *children[MAX_FILES_IN_DIR];
    struct file *files[MAX_FILES_IN_DIR];
    int num_children;
    int num_files;
};

// Create a new file
struct file *create_file(char *name, int size) {
    struct file *file = malloc(sizeof(struct file));
    strcpy(file->name, name);
    file->size = size;
    return file;
}

// Create a new directory
struct directory *create_directory(char *name, struct directory *parent) {
    struct directory *dir = malloc(sizeof(struct directory));
    strcpy(dir->name, name);
    dir->parent = parent;
    dir->num_children = 0;
    dir->num_files = 0;
    return dir;
}

// Add a file to a directory
void add_file_to_directory(struct directory *dir, struct file *file) {
    dir->files[dir->num_files++] = file;
}

// Add a directory to a directory
void add_directory_to_directory(struct directory *dir, struct directory *child) {
    dir->children[dir->num_children++] = child;
}

// Print the contents of a directory
void print_directory(struct directory *dir, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%s\n", dir->name);
    for (int i = 0; i < dir->num_files; i++) {
        for (int j = 0; j < level + 1; j++) {
            printf("  ");
        }
        printf("%s (%d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }
    for (int i = 0; i < dir->num_children; i++) {
        print_directory(dir->children[i], level + 1);
    }
}

// Main function
int main() {
    // Create the root directory
    root_dir = create_directory("/", NULL);

    // Add some files to the root directory
    add_file_to_directory(root_dir, create_file("file1.txt", 1024));
    add_file_to_directory(root_dir, create_file("file2.txt", 512));

    // Create a subdirectory in the root directory
    struct directory *subdir = create_directory("subdir", root_dir);

    // Add some files to the subdirectory
    add_file_to_directory(subdir, create_file("file3.txt", 256));
    add_file_to_directory(subdir, create_file("file4.txt", 128));

    // Print the contents of the root directory
    print_directory(root_dir, 0);

    return 0;
}