//FormAI DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File structure
typedef struct file {
    char name[50];
    int size;
    struct file *next;
} file;

// Create a new file
file *create_file(char *name, int size) {
    file *new_file = (file*) malloc(sizeof(file));
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->next = NULL;
    return new_file;
}

// Add a file to the file system
void add_file(file **filesystem, file *new_file) {
    if (*filesystem == NULL) {
        *filesystem = new_file;
        printf("Added %s to file system.\n", new_file->name);
    } else {
        file *current_file = *filesystem;
        while (current_file->next != NULL) {
            current_file = current_file->next;
        }
        current_file->next = new_file;
        printf("Added %s to file system.\n", new_file->name);
    }
}

// Remove a file from the file system
void remove_file(file **filesystem, char *name) {
    file *current_file = *filesystem;
    file *previous_file = NULL;
    if (strcmp(current_file->name, name) == 0) {
        *filesystem = current_file->next;
        free(current_file);
        printf("Removed %s from file system.\n", name);
        return;
    }
    while (current_file != NULL && strcmp(current_file->name, name) != 0) {
        previous_file = current_file;
        current_file = current_file->next;
    }
    if (current_file == NULL) {
        printf("File not found!\n");
    } else {
        previous_file->next = current_file->next;
        free(current_file);
        printf("Removed %s from file system.\n", name);
    }
}

// Print all files in the file system
void print_filesystem(file *filesystem) {
    file *current_file = filesystem;
    printf("Files in file system:\n");
    while (current_file != NULL) {
        printf("%s: %d bytes\n", current_file->name, current_file->size);
        current_file = current_file->next;
    }
    printf("\n");
}

// Main function
int main() {
    file *filesystem = NULL;
    add_file(&filesystem, create_file("file1.txt", 1024));
    add_file(&filesystem, create_file("file2.txt", 2048));
    add_file(&filesystem, create_file("file3.txt", 4096));
    print_filesystem(filesystem);
    remove_file(&filesystem, "file2.txt");
    print_filesystem(filesystem);
    remove_file(&filesystem, "file4.txt");
    return 0;
}