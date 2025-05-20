//FormAI DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare structs for file and list node
typedef struct _file {
    char* filename;
    char* content;
} File;

typedef struct _node {
    File* file;
    struct _node* next;
} Node;

// Declare global linked list for backups
Node* backups = NULL;

// Function to create a file and return a pointer to it
File* create_file(char* filename, char* content) {
    File* new_file = malloc(sizeof(File));
    new_file->filename = malloc(sizeof(char) * strlen(filename) + 1);
    new_file->content = malloc(sizeof(char) * strlen(content) + 1);
    strcpy(new_file->filename, filename);
    strcpy(new_file->content, content);
    return new_file;
}

// Function to add a file to the linked list of backups
void add_backup(File* file) {
    // Create a new node
    Node* new_node = malloc(sizeof(Node));
    new_node->file = file;
    new_node->next = NULL;

    // If the backups list is empty, make this node the head
    if (backups == NULL) {
        backups = new_node;
    } else {
        // Otherwise, traverse to the end of the list and add the node
        Node* current = backups;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the list of backups
void print_backups() {
    Node* current = backups;
    while (current != NULL) {
        printf("Backup for %s:\n%s\n", current->file->filename, current->file->content);
        current = current->next;
    }
}

int main() {
    // Create some sample files
    File* file1 = create_file("file1.txt", "This is the content of file 1.");
    File* file2 = create_file("file2.txt", "This is the content of file 2.");

    // Add them to the backups list
    add_backup(file1);
    add_backup(file2);

    // Print the backups
    printf("Backups:\n");
    print_backups();

    // Free the memory
    free(file1->filename);
    free(file1->content);
    free(file1);
    free(file2->filename);
    free(file2->content);
    free(file2);
    Node* current = backups;
    while (current != NULL) {
        Node* next = current->next;
        free(current->file->filename);
        free(current->file->content);
        free(current->file);
        free(current);
        current = next;
    }
    backups = NULL;

    return 0;
}