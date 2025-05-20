//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_SIZE 50
#define FILE_CONTENT_SIZE 256

typedef struct {
    char name[FILENAME_SIZE];
    char content[FILE_CONTENT_SIZE];
    int size;
    int is_open;
} File;

typedef struct {
    File *files[MAX_FILES];
    int file_count;
} FileSystem;

FileSystem file_system;

void initialize_file_system() {
    file_system.file_count = 0;
}

File* create_file(const char *name) {
    if (file_system.file_count >= MAX_FILES) {
        printf("Error: Maximum file limit reached.\n");
        return NULL;
    }
    File *file = (File *)malloc(sizeof(File));
    strncpy(file->name, name, FILENAME_SIZE);
    file->content[0] = '\0'; // Initialize empty content
    file->size = 0;
    file->is_open = 0;
    file_system.files[file_system.file_count++] = file;
    return file;
}

File* get_file(const char *name) {
    for (int i = 0; i < file_system.file_count; i++) {
        if (strcmp(file_system.files[i]->name, name) == 0) {
            return file_system.files[i];
        }
    }
    printf("Error: File '%s' not found.\n", name);
    return NULL;
}

void delete_file(const char *name) {
    for (int i = 0; i < file_system.file_count; i++) {
        if (strcmp(file_system.files[i]->name, name) == 0) {
            free(file_system.files[i]);
            file_system.files[i] = file_system.files[--file_system.file_count]; // Remove file
            printf("File '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}

void write_to_file(File *file, const char *content) {
    if (!file->is_open) {
        printf("Error: File '%s' is not open.\n", file->name);
        return;
    }
    
    strncpy(file->content, content, FILE_CONTENT_SIZE);
    file->size = strlen(content);
    printf("Written to file '%s': %s\n", file->name, content);
}

void open_file(File *file) {
    if (file->is_open) {
        printf("File '%s' is already open.\n", file->name);
    } else {
        file->is_open = 1;
        printf("File '%s' opened successfully.\n", file->name);
    }
}

void close_file(File *file) {
    if (!file->is_open) {
        printf("File '%s' is not open.\n", file->name);
    } else {
        file->is_open = 0;
        printf("File '%s' closed successfully.\n", file->name);
    }
}

void list_files() {
    if (file_system.file_count == 0) {
        printf("No files in the system.\n");
        return;
    }
    printf("List of files in the file system:\n");
    for (int i = 0; i < file_system.file_count; i++) {
        printf(" - %s (Size: %d bytes)\n", file_system.files[i]->name, file_system.files[i]->size);
    }
}

void cleanup() {
    for (int i = 0; i < file_system.file_count; i++) {
        free(file_system.files[i]);
    }
    file_system.file_count = 0;
}

int main() {
    initialize_file_system();

    create_file("file1.txt");
    create_file("file2.txt");
    create_file("notes.txt");

    list_files();

    File *file1 = get_file("file1.txt");
    open_file(file1);
    write_to_file(file1, "Hello, this is the content of file 1.");
    close_file(file1);

    File *file2 = get_file("file2.txt");
    open_file(file2);
    write_to_file(file2, "This is the second file's content.");
    close_file(file2);

    list_files();

    delete_file("notes.txt");
    list_files();

    cleanup();
    return 0;
}