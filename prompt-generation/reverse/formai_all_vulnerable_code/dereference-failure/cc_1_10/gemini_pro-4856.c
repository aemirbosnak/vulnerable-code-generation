//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    struct node *parent;
    struct node *child;
    struct node *sibling;
};

struct file_system {
    struct node *root;
};

struct file_system *create_file_system() {
    struct file_system *fs = malloc(sizeof(struct file_system));
    fs->root = NULL;
    return fs;
}

struct node *create_node(char *name) {
    struct node *node = malloc(sizeof(struct node));
    node->name = strdup(name);
    node->parent = NULL;
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

void add_node(struct file_system *fs, struct node *parent, struct node *child) {
    if (parent == NULL) {
        fs->root = child;
    } else {
        if (parent->child == NULL) {
            parent->child = child;
        } else {
            struct node *sibling = parent->child;
            while (sibling->sibling != NULL) {
                sibling = sibling->sibling;
            }
            sibling->sibling = child;
        }
    }
    child->parent = parent;
}

void print_file_system(struct file_system *fs) {
    struct node *node = fs->root;
    while (node != NULL) {
        printf("%s\n", node->name);
        struct node *child = node->child;
        while (child != NULL) {
            printf("  %s\n", child->name);
            child = child->sibling;
        }
        node = node->sibling;
    }
}

int main() {
    struct file_system *fs = create_file_system();
    struct node *root = create_node("/");
    add_node(fs, NULL, root);
    struct node *home = create_node("home");
    add_node(fs, root, home);
    struct node *user = create_node("user");
    add_node(fs, home, user);
    struct node *documents = create_node("documents");
    add_node(fs, user, documents);
    struct node *file1 = create_node("file1.txt");
    add_node(fs, documents, file1);
    struct node *file2 = create_node("file2.txt");
    add_node(fs, documents, file2);
    print_file_system(fs);
    return 0;
}