//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    size_t size;
    char *content;
} File;

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    File *files[MAX_FILES];
    int file_count;
} Directory;

Directory *create_directory(const char *name) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    strncpy(dir->name, name, MAX_FILENAME_LENGTH);
    dir->file_count = 0;
    return dir;
}

File *create_file(const char *name, const char *content) {
    File *file = (File *)malloc(sizeof(File));
    strncpy(file->name, name, MAX_FILENAME_LENGTH);
    file->size = strlen(content);
    file->content = (char *)malloc(file->size + 1);
    strcpy(file->content, content);
    return file;
}

void add_file_to_directory(Directory *dir, File *file) {
    if (dir->file_count < MAX_FILES) {
        dir->files[dir->file_count] = file;
        dir->file_count++;
    } else {
        printf("Directory is full, cannot add file: %s\n", file->name);
    }
}

void list_files_in_directory(Directory *dir) {
    printf("Files in directory '%s':\n", dir->name);
    for (int i = 0; i < dir->file_count; i++) {
        printf(" - %s (%zu bytes)\n", dir->files[i]->name, dir->files[i]->size);
    }
}

void delete_file_from_directory(Directory *dir, const char *filename) {
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i]->name, filename) == 0) {
            free(dir->files[i]->content);
            free(dir->files[i]);
            dir->files[i] = dir->files[dir->file_count - 1]; // Move last file into current position
            dir->file_count--;
            printf("Deleted file: %s\n", filename);
            return;
        }
    }
    printf("File not found: %s\n", filename);
}

void free_directory(Directory *dir) {
    for (int i = 0; i < dir->file_count; i++) {
        free(dir->files[i]->content);
        free(dir->files[i]);
    }
    free(dir);
}

int main() {
    Directory *root = create_directory("root");

    File *file1 = create_file("file1.txt", "Hello, this is file 1.");
    add_file_to_directory(root, file1);

    File *file2 = create_file("file2.txt", "Greetings from file 2.");
    add_file_to_directory(root, file2);

    File *file3 = create_file("file3.txt", "Content of file 3.");
    add_file_to_directory(root, file3);

    list_files_in_directory(root);

    delete_file_from_directory(root, "file2.txt");
    list_files_in_directory(root);

    delete_file_from_directory(root, "unknown.txt");

    free_directory(root);
    return 0;
}