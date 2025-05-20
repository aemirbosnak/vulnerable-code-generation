//FormAI DATASET v1.0 Category: File system simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    char name[20];
    int size;
} File;

typedef struct directory {
    char name[20];
    int num_files;
    File **files;
    struct directory *parent;
    struct directory **subdirectories;
    int num_subdirs;
} Directory;

void display_contents(Directory *dir) {
    printf("Directory: %s\n", dir->name);

    printf("Files:\n");
    for (int i = 0; i < dir->num_files; i++) {
        printf("%s (%d bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }

    printf("Subdirectories:\n");
    for (int i = 0; i < dir->num_subdirs; i++) {
        printf("%s\n", dir->subdirectories[i]->name);
    }
}

int main() {
    // create root directory
    Directory *root = (Directory *) malloc(sizeof(Directory));
    strcpy(root->name, "root");
    root->num_files = 0;
    root->files = NULL;
    root->parent = NULL;
    root->num_subdirs = 0;
    root->subdirectories = NULL;

    // create subdirectory
    Directory *subdir = (Directory *) malloc(sizeof(Directory));
    strcpy(subdir->name, "subdir");
    subdir->num_files = 0;
    subdir->files = NULL;
    subdir->parent = root;
    subdir->num_subdirs = 0;
    subdir->subdirectories = NULL;

    // add subdirectory to root
    root->num_subdirs++;
    root->subdirectories = (Directory **) realloc(root->subdirectories, root->num_subdirs * sizeof(Directory *));
    root->subdirectories[root->num_subdirs - 1] = subdir;

    // create file
    File *file = (File *) malloc(sizeof(File));
    strcpy(file->name, "file.txt");
    file->size = 100;

    // add file to subdirectory
    subdir->num_files++;
    subdir->files = (File **) realloc(subdir->files, subdir->num_files * sizeof(File *));
    subdir->files[subdir->num_files - 1] = file;

    // display contents of root directory
    display_contents(root);

    return 0;
}