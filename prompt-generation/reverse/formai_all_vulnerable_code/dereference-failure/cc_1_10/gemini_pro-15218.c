//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
typedef struct fs_node {
    char name[32];
    unsigned int size;
    struct fs_node *parent;
    struct fs_node *children;
    struct fs_node *next;
} fs_node;

// Root directory
fs_node *root = NULL;

// Current directory
fs_node *cwd = NULL;

// Create a new file or directory
fs_node *create_node(char *name, unsigned int size, fs_node *parent) {
    fs_node *node = malloc(sizeof(fs_node));
    strcpy(node->name, name);
    node->size = size;
    node->parent = parent;
    node->children = NULL;
    node->next = NULL;
    return node;
}

// Add a new node to the file system
void add_node(fs_node *node) {
    if (root == NULL) {
        root = node;
        cwd = node;
        return;
    }

    fs_node *current = root;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}

// Change directory
void cd(char *path) {
    if (strcmp(path, "..") == 0) {
        if (cwd->parent != NULL) {
            cwd = cwd->parent;
        }
        return;
    }

    fs_node *current = root;
    while (current != NULL) {
        if (strcmp(current->name, path) == 0) {
            cwd = current;
            return;
        }
        current = current->next;
    }

    printf("No such directory!\n");
}

// List files and directories in the current directory
void ls() {
    fs_node *current = cwd->children;
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

// Remove a file or directory
void rm(char *path) {
    if (strcmp(path, "..") == 0 || strcmp(path, ".") == 0) {
        printf("Cannot remove current or parent directory!\n");
        return;
    }

    fs_node *current = cwd->children;
    fs_node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, path) == 0) {
            if (previous == NULL) {
                cwd->children = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("No such file or directory!\n");
}

// Print the file system tree
void tree(fs_node *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s\n", node->name);

    fs_node *current = node->children;
    while (current != NULL) {
        tree(current, depth + 1);
        current = current->next;
    }
}

// Main function
int main() {
    // Create the root directory
    root = create_node("/", 0, NULL);
    cwd = root;

    // Create some files and directories
    add_node(create_node("file1.txt", 100, root));
    add_node(create_node("dir1", 0, root));
    add_node(create_node("file2.txt", 200, root));

    add_node(create_node("file3.txt", 300, root->children));
    add_node(create_node("dir2", 0, root->children));

    // Change directory
    cd("dir1");

    // List files and directories
    ls();

    // Remove a file
    rm("file3.txt");

    // Print the file system tree
    tree(root, 0);

    return 0;
}