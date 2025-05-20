//FormAI DATASET v1.0 Category: File system simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FS_SIZE 100 // Maximum size of the file system
#define MAX_FILENAME_LENGTH 20 // Maximum length of the file name
#define MAX_FILE_COUNT 5 // Maximum number of files that can be stored in the file system

// Define the Node structure for the file system
typedef struct node {
    char file_name[MAX_FILENAME_LENGTH];
    int file_size;
    struct node *next;
} Node;

Node *head = NULL; // Initialize the head of the linked list to NULL

// Function to add a file to the file system
bool add_file(char file_name[], int file_size) {
    if (head == NULL) { // If file system is empty
        head = (Node*) malloc(sizeof(Node)); // Allocate memory for the head node
        strcpy(head->file_name, file_name); // Copy the file name to the head node
        head->file_size = file_size; // Set the file size of the head node
        head->next = NULL; // Set the next node to NULL
        return true;
    }
    else { // If file system is not empty
        Node *current_node = head;
        while (current_node->next != NULL) { // Traverse the linked list to find the last node
            current_node = current_node->next;
        }
        if (current_node != NULL && strcmp(current_node->file_name, file_name) == 0) { // Check if the file already exists in the file system
            return false;
        }
        else if (current_node != NULL && current_node->file_size + file_size < MAX_FS_SIZE) { // Check if the file can fit in the file system
            Node *new_node = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node
            strcpy(new_node->file_name, file_name); // Copy the file name to the new node
            new_node->file_size = file_size; // Set the file size of the new node
            new_node->next = NULL; // Set the next node to NULL
            current_node->next = new_node; // Set the next node of the last node to the new node
            return true;
        }
        else {
            return false;
        }
    }
}

// Function to remove a file from the file system
bool remove_file(char file_name[]) {
    if (head != NULL && strcmp(head->file_name, file_name) == 0) { // Check if the file to be removed is the head node
        Node *temp_node = head;
        head = head->next; // Set the head to the next node
        free(temp_node); // Free the memory of the removed node
        return true;
    }
    else if (head != NULL) { // If file system is not empty and the file to be removed is not the head node
        Node *previous_node = head;
        Node *current_node = head->next;
        while (current_node != NULL && strcmp(current_node->file_name, file_name) != 0) { // Traverse the linked list to find the node to be removed
            previous_node = current_node;
            current_node = current_node->next;
        }
        if (current_node != NULL) { // If the node to be removed is found
            previous_node->next = current_node->next; // Set the next node of the previous node to the next node of the current node
            free(current_node); // Free the memory of the removed node
            return true;
        }
        else {
            return false;
        }
    }
}

// Function to display the list of files in the file system
void display_files() {
    Node *current_node = head;
    if (current_node == NULL) { // If file system is empty
        printf("No files found.\n");
    }
    else { // If file system is not empty
        printf("File system contents:\n");
        while (current_node != NULL) { // Traverse the linked list to display the files
            printf("%s - %d KB\n", current_node->file_name, current_node->file_size);
            current_node = current_node->next;
        }
    }
}

int main() {
    // Add some initial files to the file system
    add_file("file1.txt", 10);
    add_file("file2.doc", 20);
    add_file("file3.pdf", 30);

    display_files();

    // Add some files to the file system
    bool added = add_file("file4.mp3", 40);
    if (added) {
        printf("File added successfully.\n");
    }
    else {
        printf("File could not be added.\n");
    }

    added = add_file("file5.jpg", 50);
    if (added) {
        printf("File added successfully.\n");
    }
    else {
        printf("File could not be added.\n");
    }

    display_files();

    // Remove a file from the file system
    bool removed = remove_file("file2.doc");
    if (removed) {
        printf("File removed successfully.\n");
    }
    else {
        printf("File could not be removed.\n");
    }

    removed = remove_file("file6.txt");
    if (removed) {
        printf("File removed successfully.\n");
    }
    else {
        printf("File could not be removed.\n");
    }

    display_files();

    return 0;
}