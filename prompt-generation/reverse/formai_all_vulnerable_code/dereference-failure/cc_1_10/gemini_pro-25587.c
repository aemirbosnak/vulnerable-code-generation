//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom types
typedef struct {
    char* name;
    int size;
    struct FSNode* parent;
    struct FSNode* children;
    struct FSNode* next;
} FSNode;

// Function prototypes
FSNode* create_FSNode(char* name, int size);
FSNode* add_child(FSNode* parent, char* name, int size);
void print_FSNode(FSNode* node);
void print_FS(FSNode* root);
void free_FS(FSNode* root);

// Main function
int main() {
    // Create the root directory
    FSNode* root = create_FSNode("/", 0);

    // Add some subdirectories and files
    add_child(root, "bin", 0);
    add_child(root, "home", 0);
    add_child(root, "tmp", 0);
    add_child(root, "file.txt", 10);

    // Print the file system
    print_FS(root);

    // Free the file system
    free_FS(root);

    return 0;
}

// Creates a new FSNode
FSNode* create_FSNode(char* name, int size) {
    FSNode* node = malloc(sizeof(FSNode));
    node->name = strdup(name);
    node->size = size;
    node->parent = NULL;
    node->children = NULL;
    node->next = NULL;
    return node;
}

// Adds a child to a parent FSNode
FSNode* add_child(FSNode* parent, char* name, int size) {
    FSNode* child = create_FSNode(name, size);
    child->parent = parent;
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        FSNode* current = parent->children;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
    return child;
}

// Prints a single FSNode
void print_FSNode(FSNode* node) {
    printf("%s (%d bytes)\n", node->name, node->size);
}

// Prints the entire file system
void print_FS(FSNode* root) {
    FSNode* current = root;
    while (current != NULL) {
        print_FSNode(current);
        if (current->children != NULL) {
            print_FS(current->children);
        }
        current = current->next;
    }
}

// Frees the file system
void free_FS(FSNode* root) {
    FSNode* current = root;
    while (current != NULL) {
        FSNode* next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
}