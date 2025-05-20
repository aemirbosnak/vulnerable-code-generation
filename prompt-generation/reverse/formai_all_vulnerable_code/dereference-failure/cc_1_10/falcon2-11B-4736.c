//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a file system node
struct FileSystemNode {
    char filename[100];
    int size;
    struct FileSystemNode *next;
};

// Define a function to add a new file system node
struct FileSystemNode* add_file_system_node(struct FileSystemNode* head, char filename[], int size) {
    struct FileSystemNode* new_node = (struct FileSystemNode*)malloc(sizeof(struct FileSystemNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    strcpy(new_node->filename, filename);
    new_node->size = size;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct FileSystemNode* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}

// Define a function to display the file system nodes
void display_file_system_nodes(struct FileSystemNode* head) {
    struct FileSystemNode* current = head;
    while (current!= NULL) {
        printf("%s: size=%d\n", current->filename, current->size);
        current = current->next;
    }
}

int main() {
    // Initialize the head of the file system
    struct FileSystemNode* head = NULL;

    // Add some file system nodes
    add_file_system_node(head, "file1.txt", 100);
    add_file_system_node(head, "file2.txt", 200);
    add_file_system_node(head, "file3.txt", 150);

    // Display the file system nodes
    display_file_system_nodes(head);

    return 0;
}