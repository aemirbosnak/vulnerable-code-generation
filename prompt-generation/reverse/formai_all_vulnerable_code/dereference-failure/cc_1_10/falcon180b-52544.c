//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024

// Node structure for linked list implementation of file system
typedef struct node {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char *data;
    struct node *next;
} Node;

// Initialize an empty file system
Node *init() {
    Node *root = malloc(sizeof(Node));
    root->next = NULL;
    return root;
}

// Create a new file with given name and size
Node *create_file(Node *fs, char *name, int size) {
    Node *new_file = malloc(sizeof(Node));
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->data = malloc(size);
    new_file->next = fs->next;
    fs->next = new_file;
    return new_file;
}

// Open an existing file with given name
Node *open_file(Node *fs, char *name) {
    Node *current = fs->next;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Write data to an open file
void write_file(Node *file, char *data, int length) {
    int offset = 0;
    while (offset < length && offset < file->size) {
        strncpy(file->data + offset, data, length);
        offset += length;
    }
}

// Read data from an open file
char *read_file(Node *file, int length) {
    return file->data;
}

// Close an open file
void close_file(Node *file) {
    // Do nothing for now
}

// Delete a file from the file system
void delete_file(Node *fs, char *name) {
    Node *current = fs->next;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            Node *temp = current->next;
            free(current->data);
            free(current);
            current = temp;
        } else {
            current = current->next;
        }
    }
}

// List all files in the file system
void list_files(Node *fs) {
    Node *current = fs->next;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    Node *fs = init();
    create_file(fs, "test.txt", 10);
    open_file(fs, "test.txt");
    write_file(fs->next, "Hello, world!", strlen("Hello, world!"));
    list_files(fs);
    close_file(fs->next);
    delete_file(fs, "test.txt");
    return 0;
}