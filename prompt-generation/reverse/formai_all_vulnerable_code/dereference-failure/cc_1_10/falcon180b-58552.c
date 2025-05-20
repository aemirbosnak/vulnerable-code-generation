//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 64
#define MAX_FILE_CONTENT_SIZE 1024

// Node structure for linked list
typedef struct node {
    char file_name[MAX_FILE_NAME_SIZE];
    char file_content[MAX_FILE_CONTENT_SIZE];
    struct node* next;
} Node;

// Linked list structure
Node* root = NULL;

// Function to create a new file
void create_file(char* file_name, char* file_content) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->file_name, file_name);
    strcpy(new_node->file_content, file_content);
    new_node->next = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        Node* temp = root;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to read a file
void read_file(char* file_name) {
    Node* temp = root;
    while (temp!= NULL) {
        if (strcmp(temp->file_name, file_name) == 0) {
            printf("File content: %s\n", temp->file_content);
            return;
        }
        temp = temp->next;
    }
    printf("File not found.\n");
}

// Function to delete a file
void delete_file(char* file_name) {
    Node* temp = root;
    Node* prev = NULL;

    while (temp!= NULL && strcmp(temp->file_name, file_name)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("File not found.\n");
        return;
    }

    if (prev == NULL) {
        root = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

int main() {
    create_file("test.txt", "Hello, world!");
    read_file("test.txt");
    delete_file("test.txt");

    return 0;
}