//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct file_system {
    char *name;
    char *content;
    int size;
    struct file_system *next;
} file_system;

// Create a new file
file_system *create_file(char *name, char *content, int size) {
    file_system *file = malloc(sizeof(file_system));
    file->name = strdup(name);
    file->content = strdup(content);
    file->size = size;
    file->next = NULL;
    return file;
}

// Add a file to the file system
void add_file(file_system **head, file_system *file) {
    if (*head == NULL) {
        *head = file;
    } else {
        file_system *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = file;
    }
}

// Print the file system
void print_file_system(file_system *head) {
    file_system *current = head;
    while (current != NULL) {
        printf("%s (%d bytes)\n", current->name, current->size);
        current = current->next;
    }
}

// Delete a file from the file system
void delete_file(file_system **head, char *name) {
    file_system *current = *head;
    file_system *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free(current->content);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    // Create a new file system
    file_system *head = NULL;

    // Add some files to the file system
    add_file(&head, create_file("file1.txt", "Hello, world!", 13));
    add_file(&head, create_file("file2.txt", "This is a test file.", 20));
    add_file(&head, create_file("file3.txt", "This is another test file.", 27));

    // Print the file system
    print_file_system(head);

    // Delete a file from the file system
    delete_file(&head, "file2.txt");

    // Print the file system
    print_file_system(head);

    // Free the file system
    file_system *current = head;
    while (current != NULL) {
        file_system *next = current->next;
        free(current->name);
        free(current->content);
        free(current);
        current = next;
    }

    return 0;
}