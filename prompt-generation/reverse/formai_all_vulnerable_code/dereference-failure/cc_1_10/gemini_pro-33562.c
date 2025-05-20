//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct {
    char *name;
    int size;
    int num_blocks;
    int *blocks;
} File;

// Directory structure
typedef struct {
    char *name;
    int num_files;
    File **files;
} Directory;

// Create a new file
File *create_file(char *name, int size) {
    File *file = malloc(sizeof(File));
    file->name = strdup(name);
    file->size = size;
    file->num_blocks = (size + 511) / 512;
    file->blocks = malloc(sizeof(int) * file->num_blocks);
    for (int i = 0; i < file->num_blocks; i++) {
        file->blocks[i] = -1;
    }
    return file;
}

// Create a new directory
Directory *create_directory(char *name) {
    Directory *dir = malloc(sizeof(Directory));
    dir->name = strdup(name);
    dir->num_files = 0;
    dir->files = NULL;
    return dir;
}

// Add a file to a directory
void add_file_to_directory(Directory *dir, File *file) {
    dir->files = realloc(dir->files, sizeof(File *) * (dir->num_files + 1));
    dir->files[dir->num_files++] = file;
}

// Print the file system
void print_file_system(Directory *root) {
    printf("%s\n", root->name);
    for (int i = 0; i < root->num_files; i++) {
        printf("  %s (%d bytes)\n", root->files[i]->name, root->files[i]->size);
    }
    for (int i = 0; i < root->num_files; i++) {
        if (root->files[i]->num_blocks > 0) {
            printf("    Blocks: ");
            for (int j = 0; j < root->files[i]->num_blocks; j++) {
                printf("%d ", root->files[i]->blocks[j]);
            }
            printf("\n");
        }
    }
}

// Main function
int main() {
    // Create the root directory
    Directory *root = create_directory("/");

    // Create some files
    File *file1 = create_file("file1.txt", 1024);
    File *file2 = create_file("file2.txt", 2048);
    File *file3 = create_file("file3.txt", 4096);

    // Add the files to the root directory
    add_file_to_directory(root, file1);
    add_file_to_directory(root, file2);
    add_file_to_directory(root, file3);

    // Print the file system
    print_file_system(root);

    return 0;
}