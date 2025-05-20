//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000

// Node structure for linked list
typedef struct node {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    unsigned char *data;
    struct node *next;
} Node;

Node *root = NULL;

// Function to create a new file
void create_file(char *name, int size) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->size = size;
    new_node->data = (unsigned char *) malloc(size);
    new_node->next = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        Node *temp = root;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to open an existing file
Node *open_file(char *name) {
    Node *temp = root;
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to read data from a file
void read_file(Node *file_node, int offset, int length, unsigned char *buffer) {
    int i;
    for (i = 0; i < length; i++) {
        buffer[i] = file_node->data[offset + i];
    }
}

// Function to write data to a file
void write_file(Node *file_node, int offset, int length, unsigned char *buffer) {
    int i;
    for (i = 0; i < length; i++) {
        file_node->data[offset + i] = buffer[i];
    }
}

int main() {
    // Example usage
    create_file("test.txt", 10);
    Node *file_node = open_file("test.txt");
    write_file(file_node, 0, 5, "Hello");
    read_file(file_node, 0, 5, (unsigned char *) "World");
    printf("%s", file_node->data);
    return 0;
}