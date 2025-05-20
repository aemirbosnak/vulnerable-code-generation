//FormAI DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

typedef struct dir {
    char name[50];
    int num_files;
    struct file *files[MAX_FILE_SIZE];
    struct dir *subdirs[MAX_FILE_SIZE];
    int num_subdirs;
} Dir;

typedef struct file {
    char name[50];
    char extension[10];
    int size;
    char data[MAX_FILE_SIZE];
} File;

// creates a new file with given name, extension, and data
File* create_file(char* name, char* extension, char* data) {
    File* new_file = malloc(sizeof(File));
    strcpy(new_file->name, name);
    strcpy(new_file->extension, extension);
    new_file->size = strlen(data);
    strcpy(new_file->data, data);
    return new_file;
}

// adds a file to a directory
void add_file_to_dir(Dir* dir, File* file) {
    dir->files[dir->num_files++] = file;
}

// creates a new directory with the given name
Dir* create_dir(char* name) {
    Dir* new_dir = malloc(sizeof(Dir));
    strcpy(new_dir->name, name);
    new_dir->num_files = 0;
    new_dir->num_subdirs = 0;
    return new_dir;
}

// adds a subdirectory to a directory
void add_subdir_to_dir(Dir* dir, Dir* subdir) {
    dir->subdirs[dir->num_subdirs++] = subdir;
}

// searches a directory for a file with the given name and extension
File* find_file_in_dir(Dir* dir, char* name, char* extension) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i]->name, name) == 0 && strcmp(dir->files[i]->extension, extension) == 0) {
            return dir->files[i];
        }
    }
    return NULL;
}

// searches a directory for a subdirectory with the given name
Dir* find_subdir_in_dir(Dir* dir, char* name) {
    for (int i = 0; i < dir->num_subdirs; i++) {
        if (strcmp(dir->subdirs[i]->name, name) == 0) {
            return dir->subdirs[i];
        }
    }
    return NULL;
}

int main() {
    Dir* root_dir = create_dir("root");

    // create some files and add them to the root directory
    File* file1 = create_file("file1", "txt", "Hello world!");
    add_file_to_dir(root_dir, file1);

    File* file2 = create_file("file2", "dat", "Some data");
    add_file_to_dir(root_dir, file2);

    // create a subdirectory and add it to the root directory
    Dir* sub_dir = create_dir("sub");
    add_subdir_to_dir(root_dir, sub_dir);

    // create a file and add it to the subdirectory
    File* file3 = create_file("file3", "txt", "Some more text");
    add_file_to_dir(sub_dir, file3);

    // search for a file in the root directory
    File* found_file = find_file_in_dir(root_dir, "file1", "txt");
    if (found_file != NULL) {
        printf("Found file: %s.%s\n", found_file->name, found_file->extension);
    } else {
        printf("File not found.\n");
    }

    // search for a subdirectory in the root directory
    Dir* found_subdir = find_subdir_in_dir(root_dir, "sub");
    if (found_subdir != NULL) {
        printf("Found subdirectory: %s\n", found_subdir->name);
    } else {
        printf("Subdirectory not found.\n");
    }

    return 0;
}