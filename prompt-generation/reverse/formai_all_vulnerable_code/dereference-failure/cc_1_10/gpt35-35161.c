//FormAI DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_NAME_LENGTH]; // file name
    int size; // file size
    char *data; // file contents
} file;

typedef struct {
    int total_size; // total size of file system
    int used_size; // used size of file system
    file files[MAX_FILES]; // files in file system
} file_system;

// creates an empty file system
file_system *create_file_system(int size) {
    file_system *fs = (file_system*) malloc(sizeof(file_system));
    fs->total_size = size;
    fs->used_size = 0;
    return fs;
}

// adds a file to the file system
void add_file(file_system *fs, char *name, char *data, int size) {
    if (fs->used_size + size > fs->total_size) {
        printf("Not enough space in file system\n");
        return;
    }
    file new_file;
    strncpy(new_file.name, name, MAX_NAME_LENGTH);
    new_file.size = size;
    new_file.data = (char*) malloc(size);
    memcpy(new_file.data, data, size);
    fs->files[fs->used_size] = new_file;
    fs->used_size += size;
}

// deletes a file from the file system
void delete_file(file_system *fs, char *name) {
    int found = 0;
    int i;
    for (i = 0; i < fs->used_size; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("File not found\n");
        return;
    }
    fs->used_size -= fs->files[i].size;
    int j;
    for (j = i; j < fs->used_size; j++) {
        fs->files[j] = fs->files[j + 1];
    }
}

// prints all files in the file system
void print_files(file_system *fs) {
    printf("Files in file system:\n");
    int i;
    for (i = 0; i < fs->used_size; i++) {
        printf("  %s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

int main() {
    file_system *fs = create_file_system(MAX_FILE_SIZE * MAX_FILES);
    add_file(fs, "file1.txt", "This is file 1", 15);
    add_file(fs, "file2.txt", "This is file 2", 15);
    print_files(fs);
    delete_file(fs, "file2.txt");
    print_files(fs);
    return 0;
}