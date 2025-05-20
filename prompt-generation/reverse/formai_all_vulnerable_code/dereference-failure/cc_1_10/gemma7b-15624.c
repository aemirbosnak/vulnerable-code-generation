//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the file system structure
typedef struct FileSystem {
    char **dirs;
    int dir_size;
    char **files;
    int file_size;
    int current_dir;
} FileSystem;

// Create a new file system
FileSystem *create_fs(int dir_size, int file_size) {
    FileSystem *fs = malloc(sizeof(FileSystem));
    fs->dirs = malloc(dir_size * sizeof(char *));
    fs->dir_size = dir_size;
    fs->files = malloc(file_size * sizeof(char *));
    fs->file_size = file_size;
    fs->current_dir = 0;

    return fs;
}

// List the files in a directory
void list_files(FileSystem *fs) {
    int i;
    char **files = fs->files;

    for (i = 0; files[i] != NULL; i++) {
        printf("%s\n", files[i]);
    }
}

// Create a new file
void create_file(FileSystem *fs, char *name) {
    int i;
    char **files = fs->files;

    for (i = 0; files[i] != NULL; i++) {
        if (strcmp(files[i], name) == 0) {
            printf("Error: File already exists.\n");
            return;
        }
    }

    files[fs->file_size++] = name;
}

// Main function
int main() {
    FileSystem *fs = create_fs(10, 20);

    create_file(fs, "test.txt");
    create_file(fs, "my.doc");

    list_files(fs);

    return 0;
}