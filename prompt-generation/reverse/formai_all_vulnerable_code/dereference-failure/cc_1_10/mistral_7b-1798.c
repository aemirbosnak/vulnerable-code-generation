//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Node *left, *right;
} Node;

Node *create_node(const char *name, int age) {
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

bool is_empty(Node *root) {
    return root == NULL;
}

Node *insert(Node *root, const char *name, int age) {
    if (is_empty(root)) {
        root = create_node(name, age);
        return root;
    }

    Node *current = root;
    Node *parent;

    while (1) {
        if (!strcmp(name, current->name)) {
            fprintf(stderr, "Error: Name already exists in the tree.\n");
            free(name);
            free(current);
            return root;
        }

        parent = current;

        if (strcmp(name, current->name) < 0) {
            current = current->left;
            if (is_empty(current)) {
                parent->left = create_node(name, age);
                break;
            }
        } else {
            current = current->right;
            if (is_empty(current)) {
                parent->right = create_node(name, age);
                break;
            }
        }
    }

    return root;
}

void print_tree(Node *root, int level) {
    if (is_empty(root)) {
        return;
    }

    print_tree(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("-%s-%d-\n", root->name, root->age);

    print_tree(root->left, level + 1);
}

int main() {
    Node *root = NULL;

    const char *names[] = {
        "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace"
    };

    int ages[] = {
        25, 30, 22, 35, 28, 45, 32
    };

    for (size_t i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
        root = insert(root, names[i], ages[i]);
    }

    print_tree(root, 0);

    return 0;
}