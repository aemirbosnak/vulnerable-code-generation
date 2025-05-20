//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_FILE_NAME 255
#define MAX_FILES 100
#define MAX_DIRS 10

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char *data;
} File;

typedef struct {
    char name[MAX_FILE_NAME];
    File *files[MAX_FILES];
    int file_count;
} Directory;

Directory *create_directory(const char *name) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    strncpy(dir->name, name, MAX_FILE_NAME);
    dir->file_count = 0;
    return dir;
}

File *create_file(const char *name, const char *data) {
    File *file = (File *)malloc(sizeof(File));
    strncpy(file->name, name, MAX_FILE_NAME);
    file->size = strlen(data);
    file->data = (char *)malloc(file->size + 1);
    strcpy(file->data, data);
    return file;
}

void add_file_to_directory(Directory *dir, File *file) {
    if (dir->file_count < MAX_FILES) {
        dir->files[dir->file_count++] = file;
    } else {
        printf("Directory is full. Cannot add more files.\n");
    }
}

void list_directory(const Directory *dir) {
    printf("Directory: %s\n", dir->name);
    for (int i = 0; i < dir->file_count; i++) {
        printf("  File %d: %s (Size: %d bytes)\n", i + 1, dir->files[i]->name, dir->files[i]->size);
    }
}

void delete_file(Directory *dir, const char *filename) {
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i]->name, filename) == 0) {
            free(dir->files[i]->data);
            free(dir->files[i]);
            dir->files[i] = dir->files[--dir->file_count];
            printf("Deleted file: %s\n", filename);
            return;
        }
    }
    printf("File not found: %s\n", filename);
}

void free_directory(Directory *dir) {
    for (int i = 0; i < dir->file_count; i++) {
        free(dir->files[i]->data);
        free(dir->files[i]);
    }
    free(dir);
}

int main() {
    Directory *root = create_directory("root");
    
    // Adding files to the directory
    add_file_to_directory(root, create_file("file1.txt", "This is the content of file 1."));
    add_file_to_directory(root, create_file("file2.txt", "Hello, this is file 2."));
    add_file_to_directory(root, create_file("file3.txt", "Content of the third file."));
    
    // List files in the directory
    list_directory(root);

    // Perform deletion
    printf("\nPerforming file deletion:\n");
    delete_file(root, "file2.txt");

    // List files after deletion
    list_directory(root);

    // Clean up
    printf("\nCleaning up...\n");
    free_directory(root);

    return 0;
}