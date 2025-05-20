//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_CONTENTS_LENGTH 1000

// Node structure for the linked list
typedef struct node {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_contents[MAX_FILE_CONTENTS_LENGTH];
    struct node* next;
} Node;

// Function to create a new file
void create_file(Node** head, char* file_name, char* file_contents) {
    // Check if the file already exists
    Node* current = *head;
    while (current!= NULL && strcmp(current->file_name, file_name)!= 0) {
        current = current->next;
    }
    if (current!= NULL) {
        printf("File already exists.\n");
        return;
    }

    // Create the new file
    Node* new_file = (Node*) malloc(sizeof(Node));
    strcpy(new_file->file_name, file_name);
    strcpy(new_file->file_contents, file_contents);
    new_file->next = NULL;

    if (*head == NULL) {
        *head = new_file;
    } else {
        current->next = new_file;
    }

    printf("File created successfully.\n");
}

// Function to read a file
void read_file(Node* head, char* file_name) {
    // Look for the file
    Node* current = head;
    while (current!= NULL && strcmp(current->file_name, file_name)!= 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("File not found.\n");
        return;
    }

    // Print the file contents
    printf("File contents:\n%s\n", current->file_contents);
}

// Function to delete a file
void delete_file(Node** head, char* file_name) {
    // Look for the file
    Node* current = *head;
    Node* previous = NULL;
    while (current!= NULL && strcmp(current->file_name, file_name)!= 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("File not found.\n");
        return;
    }

    // Delete the file
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);

    printf("File deleted successfully.\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Example usage
    create_file(&head, "example.txt", "This is an example file.");
    read_file(head, "example.txt");
    delete_file(&head, "example.txt");

    return 0;
}