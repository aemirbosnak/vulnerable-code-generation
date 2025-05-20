//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// File system structure
typedef struct file_system {
    char *name;
    size_t size;
    char *data;
    struct file_system *next;
} file_system;

// Initialize the file system
file_system *init_file_system() {
    file_system *fs = malloc(sizeof(file_system));
    fs->name = NULL;
    fs->size = 0;
    fs->data = NULL;
    fs->next = NULL;
    return fs;
}

// Create a new file
file_system *create_file(file_system *fs, char *name, size_t size) {
    file_system *new_file = malloc(sizeof(file_system));
    new_file->name = malloc(strlen(name) + 1);
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->data = malloc(size);
    new_file->next = fs;
    return new_file;
}

// Delete a file
void delete_file(file_system *fs, char *name) {
    file_system *prev = NULL;
    file_system *curr = fs;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            if (prev == NULL) {
                fs = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr->name);
            free(curr->data);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Read a file
void read_file(file_system *fs, char *name) {
    file_system *curr = fs;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            printf("%s\n", curr->data);
            return;
        }
        curr = curr->next;
    }
    printf("File not found\n");
}

// Write to a file
void write_file(file_system *fs, char *name, char *data) {
    file_system *curr = fs;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            strcpy(curr->data, data);
            return;
        }
        curr = curr->next;
    }
    printf("File not found\n");
}

// List all files
void list_files(file_system *fs) {
    file_system *curr = fs;
    while (curr != NULL) {
        printf("%s\n", curr->name);
        curr = curr->next;
    }
}

// Main function
int main() {
    // Initialize the file system
    file_system *fs = init_file_system();

    // Create a few files
    create_file(fs, "file1.txt", 100);
    create_file(fs, "file2.txt", 200);
    create_file(fs, "file3.txt", 300);

    // List all files
    list_files(fs);

    // Read a file
    read_file(fs, "file2.txt");

    // Write to a file
    write_file(fs, "file3.txt", "This is a test");

    // Delete a file
    delete_file(fs, "file1.txt");

    // List all files
    list_files(fs);

    return 0;
}