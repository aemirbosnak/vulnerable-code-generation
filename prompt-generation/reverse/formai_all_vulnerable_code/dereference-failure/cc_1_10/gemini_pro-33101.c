//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system simulation

// File system structure
typedef struct fs_node {
    char *name;
    int size;
    struct fs_node *parent;
    struct fs_node *child;
    struct fs_node *sibling;
} fs_node;

// File system root
fs_node *root = NULL;

// Create a new file system node
fs_node *fs_create_node(char *name, int size, fs_node *parent) {
    fs_node *node = malloc(sizeof(fs_node));
    node->name = strdup(name);
    node->size = size;
    node->parent = parent;
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

// Add a file to the file system
void fs_add_file(char *path, int size) {
    fs_node *node = root;
    char *token;
    char *rest = path;

    // Split the path into tokens
    while ((token = strtok_r(rest, "/", &rest))) {
        // Find the child node with the given name
        fs_node *child = node->child;
        while (child) {
            if (!strcmp(child->name, token)) {
                break;
            }
            child = child->sibling;
        }

        // If the child node does not exist, create it
        if (!child) {
            child = fs_create_node(token, 0, node);
            child->sibling = node->child;
            node->child = child;
        }

        // Update the current node
        node = child;
    }

    // Add the file to the current node
    node->size += size;
}

// Print the file system
void fs_print(fs_node *node, int level) {
    // Print the current node
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%s (%d)\n", node->name, node->size);

    // Print the child nodes
    fs_node *child = node->child;
    while (child) {
        fs_print(child, level + 1);
        child = child->sibling;
    }
}

// Main function
int main() {
    // Create the root node
    root = fs_create_node("/", 0, NULL);

    // Add some files to the file system
    fs_add_file("/bin/ls", 1024);
    fs_add_file("/bin/cat", 1024);
    fs_add_file("/usr/bin/python", 2048);
    fs_add_file("/usr/bin/java", 4096);
    fs_add_file("/home/user/Documents/file1.txt", 1024);
    fs_add_file("/home/user/Documents/file2.txt", 2048);

    // Print the file system
    fs_print(root, 0);

    return 0;
}