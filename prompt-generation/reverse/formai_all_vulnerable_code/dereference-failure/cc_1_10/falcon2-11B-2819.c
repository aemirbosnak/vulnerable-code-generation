//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    char* name;
    char* content;
    int size;
} File;

typedef struct directory {
    char* name;
    File** files;
    int num_files;
} Directory;

void add_file(Directory* directory, char* name, char* content) {
    File* new_file = malloc(sizeof(File));
    new_file->name = name;
    new_file->content = content;
    new_file->size = strlen(content);

    directory->files = realloc(directory->files, (directory->num_files + 1) * sizeof(File*));
    directory->files[directory->num_files] = new_file;
    directory->num_files++;
}

void remove_file(Directory* directory, char* name) {
    int i;
    for (i = 0; i < directory->num_files; i++) {
        if (strcmp(directory->files[i]->name, name) == 0) {
            free(directory->files[i]);
            directory->files[i] = NULL;
            directory->num_files--;
            break;
        }
    }
}

void print_directory(Directory* directory) {
    int i;
    for (i = 0; i < directory->num_files; i++) {
        printf("%s\n", directory->files[i]->name);
    }
}

int main() {
    Directory* root_dir = malloc(sizeof(Directory));
    root_dir->name = "root";
    root_dir->files = NULL;
    root_dir->num_files = 0;

    add_file(root_dir, "file1.txt", "This is file 1.");
    add_file(root_dir, "file2.txt", "This is file 2.");

    print_directory(root_dir);

    remove_file(root_dir, "file1.txt");

    print_directory(root_dir);

    return 0;
}