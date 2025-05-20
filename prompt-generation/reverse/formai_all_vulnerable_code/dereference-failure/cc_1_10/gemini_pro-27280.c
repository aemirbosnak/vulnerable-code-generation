//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    char *number;
    struct node *left;
    struct node *right;
};

struct node *create_node(char *name, char *number) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->name = strdup(name);
    new_node->number = strdup(number);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(struct node **root, char *name, char *number) {
    if (*root == NULL) {
        *root = create_node(name, number);
        printf("Inserted %s (%s) into the phone book.\n", name, number);
    } else if (strcmp(name, (*root)->name) < 0) {
        insert_node(&(*root)->left, name, number);
    } else {
        insert_node(&(*root)->right, name, number);
    }
}

struct node *find_node(struct node *root, char *name) {
    if (root == NULL) {
        return NULL;
    } else if (strcmp(name, root->name) == 0) {
        return root;
    } else if (strcmp(name, root->name) < 0) {
        return find_node(root->left, name);
    } else {
        return find_node(root->right, name);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <name> <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct node *root = NULL;
    for (int i = 1; i < argc; i += 2) {
        insert_node(&root, argv[i], argv[i + 1]);
    }

    while (1) {
        char name[256];
        printf("Enter a name to search for (or q to quit): ");
        scanf("%s", name);
        if (strcmp(name, "q") == 0) {
            break;
        }

        struct node *node = find_node(root, name);
        if (node != NULL) {
            printf("%s (%s)\n", node->name, node->number);
        } else {
            printf("No entry found for %s.\n", name);
        }
    }

    return EXIT_SUCCESS;
}