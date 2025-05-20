//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEPTH 5
#define MAX_LEN 20

// Structure to represent a tree node
typedef struct node {
    char word[MAX_LEN];
    int depth;
    struct node *left, *right;
} node_t;

// Function to create a new node
node_t *new_node(char *word, int depth) {
    node_t *n = (node_t *)malloc(sizeof(node_t));
    strcpy(n->word, word);
    n->depth = depth;
    n->left = n->right = NULL;
    return n;
}

// Function to insert a node into the tree
void insert_node(node_t **root, char *word) {
    int depth = 0;
    node_t *cur = *root;

    while (cur != NULL && strcmp(word, cur->word) > 0) {
        depth++;
        cur = cur->left;
    }

    if (cur == NULL || strcmp(word, cur->word) == 0) {
        node_t *n = new_node(word, depth);
        if (cur == NULL) {
            *root = n;
        } else {
            cur->left = n;
        }
    }
}

// Function to print the tree
void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }

    printf("%s (%d) ", root->word, root->depth);

    if (root->left != NULL) {
        print_tree(root->left);
        printf("  ");
    }

    if (root->right != NULL) {
        print_tree(root->right);
        printf("  ");
    }

    printf("\n");
}

int main() {
    node_t *root = NULL;

    // Insert nodes into the tree
    insert_node(&root, "apple");
    insert_node(&root, "banana");
    insert_node(&root, "cherry");
    insert_node(&root, "date");
    insert_node(&root, "elderberry");

    // Print the tree
    print_tree(root);

    return 0;
}