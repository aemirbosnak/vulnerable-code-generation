//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

// Custom file system data structures

typedef struct File {
    char *name;
    int size;
    char *contents;
} File;

typedef struct Directory {
    char *name;
    File **files;
    int num_files;
} Directory;

// Global file system variables

Directory *root_dir;
Directory *current_dir;

// Utility functions

File *find_file(Directory *dir, char *name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->name, name) == 0) {
            return dir->files[i];
        }
    }
    return NULL;
}

Directory *find_dir(Directory *dir, char *name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->name, name) == 0 && dir->files[i]->size == 0) {
            return dir->files[i];
        }
    }
    return NULL;
}

// File system operations

void create_file(char *name, int size) {
    File *file = malloc(sizeof(File));
    file->name = strdup(name);
    file->size = size;
    file->contents = malloc(size);
    current_dir->files = realloc(current_dir->files, (current_dir->num_files + 1) * sizeof(File *));
    current_dir->files[current_dir->num_files++] = file;
}

void create_dir(char *name) {
    Directory *dir = malloc(sizeof(Directory));
    dir->name = strdup(name);
    dir->files = NULL;
    dir->num_files = 0;
    current_dir->files = realloc(current_dir->files, (current_dir->num_files + 1) * sizeof(File *));
    current_dir->files[current_dir->num_files++] = dir;
}

void delete_file(char *name) {
    File *file = find_file(current_dir, name);
    if (file != NULL) {
        for (int i = 0; i < current_dir->num_files; i++) {
            if (current_dir->files[i] == file) {
                free(file->name);
                free(file->contents);
                for (int j = i + 1; j < current_dir->num_files; j++) {
                    current_dir->files[j - 1] = current_dir->files[j];
                }
                current_dir->num_files--;
                break;
            }
        }
    }
}

void delete_dir(char *name) {
    Directory *dir = find_dir(current_dir, name);
    if (dir != NULL) {
        for (int i = 0; i < current_dir->num_files; i++) {
            if (current_dir->files[i] == dir) {
                for (int j = 0; j < dir->num_files; j++) {
                    delete_file(dir->files[j]->name);
                }
                free(dir->name);
                free(dir->files);
                for (int j = i + 1; j < current_dir->num_files; j++) {
                    current_dir->files[j - 1] = current_dir->files[j];
                }
                current_dir->num_files--;
                break;
            }
        }
    }
}

void cd(char *name) {
    Directory *dir = find_dir(current_dir, name);
    if (dir != NULL) {
        current_dir = dir;
    }
}

void ls() {
    for (int i = 0; i < current_dir->num_files; i++) {
        if (current_dir->files[i]->size == 0) {
            printf("%s\n", current_dir->files[i]->name);
        } else {
            printf("%s (%d bytes)\n", current_dir->files[i]->name, current_dir->files[i]->size);
        }
    }
}

// Main function

int main() {
    // Initialize file system
    root_dir = malloc(sizeof(Directory));
    root_dir->name = strdup("/");
    root_dir->files = NULL;
    root_dir->num_files = 0;
    current_dir = root_dir;

    // Create some files and directories
    create_file("file1.txt", 100);
    create_file("file2.txt", 200);
    create_dir("dir1");
    create_dir("dir2");

    // Change directory
    cd("dir1");

    // Create another file
    create_file("file3.txt", 300);

    // List directory contents
    ls();

    // Delete a file
    delete_file("file2.txt");

    // Delete a directory
    delete_dir("dir2");

    // List directory contents again
    ls();

    // Free memory
    free(root_dir->name);
    free(root_dir->files);
    free(root_dir);

    return 0;
}