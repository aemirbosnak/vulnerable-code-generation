//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the file system structure
typedef struct file_system {
    char *name;
    int size;
    time_t last_modified;
    struct file_system *next;
} file_system;

// Create a new file system
file_system *create_file_system() {
    file_system *fs = malloc(sizeof(file_system));
    fs->name = NULL;
    fs->size = 0;
    fs->last_modified = time(NULL);
    fs->next = NULL;
    return fs;
}

// Add a file to the file system
void add_file(file_system *fs, char *name, int size) {
    // Create a new file
    file_system *file = malloc(sizeof(file_system));
    file->name = strdup(name);
    file->size = size;
    file->last_modified = time(NULL);
    file->next = NULL;

    // Add the file to the file system
    file_system *curr = fs;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = file;
}

// Remove a file from the file system
void remove_file(file_system *fs, char *name) {
    // Find the file to remove
    file_system *curr = fs;
    while (curr->next != NULL && strcmp(curr->next->name, name) != 0) {
        curr = curr->next;
    }

    // Remove the file from the file system
    if (curr->next != NULL) {
        file_system *file = curr->next;
        curr->next = file->next;
        free(file->name);
        free(file);
    }
}

// Print the file system
void print_file_system(file_system *fs) {
    file_system *curr = fs;
    while (curr != NULL) {
        printf("%s (%d bytes, last modified %s)\n", curr->name, curr->size, ctime(&curr->last_modified));
        curr = curr->next;
    }
}

// Free the file system
void free_file_system(file_system *fs) {
    file_system *curr = fs;
    while (curr != NULL) {
        file_system *next = curr->next;
        free(curr->name);
        free(curr);
        curr = next;
    }
}

// Main function
int main() {
    // Create a new file system
    file_system *fs = create_file_system();

    // Add some files to the file system
    add_file(fs, "file1.txt", 100);
    add_file(fs, "file2.txt", 200);
    add_file(fs, "file3.txt", 300);

    // Print the file system
    print_file_system(fs);

    // Remove a file from the file system
    remove_file(fs, "file2.txt");

    // Print the file system
    print_file_system(fs);

    // Free the file system
    free_file_system(fs);

    return 0;
}