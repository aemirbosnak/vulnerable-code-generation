//FormAI DATASET v1.0 Category: Data structures visualization ; Style: careful
/*
 * This program displays a visualization of a binary search tree
 * using ASCII characters. It asks the user for input to build the tree
 * dynamically, and shows the current state of the tree after each insertion.
 * It also allows the user to search for a value in the tree and highlights
 * the path taken to find the node.
 * 
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DEPTH 10

/* The node structure for the binary search tree */
typedef struct bst_node {
    int value;                  /* The value stored in the node */
    struct bst_node *left;      /* Pointer to the left child */
    struct bst_node *right;     /* Pointer to the right child */
} bst_node_t;

/* Function prototypes */
void display_tree(bst_node_t *root, int depth, int pos, int search_value);
void search_tree(bst_node_t *root, int value);

/* The main function */
int main() {
    bst_node_t *root = NULL;
    int value;
    char response[10];

    /* Ask the user for input to build the tree */
    do {
        printf("Enter a value to insert into the tree: ");
        scanf("%d", &value);
        getchar();  /* Remove the newline character from the input buffer */

        /* Insert the value into the tree */
        bst_node_t *new_node = (bst_node_t *) malloc(sizeof(bst_node_t));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;

        if (root == NULL) {
            root = new_node;
        } else {
            bst_node_t *current_node = root;
            while (true) {
                if (value < current_node->value) {
                    /* Insert into the left subtree */
                    if (current_node->left == NULL) {
                        current_node->left = new_node;
                        break;
                    } else {
                        current_node = current_node->left;
                    }
                } else {
                    /* Insert into the right subtree */
                    if (current_node->right == NULL) {
                        current_node->right = new_node;
                        break;
                    } else {
                        current_node = current_node->right;
                    }
                }
            }
        }

        /* Display the tree */
        display_tree(root, 0, 0, 0);

        printf("Insert another value? (y/n): ");
        fgets(response, 10, stdin);
    } while (response[0] == 'y');

    /* Ask the user to search for a value in the tree */
    printf("Enter a value to search for in the tree: ");
    scanf("%d", &value);
    getchar();  /* Remove the newline character from the input buffer */

    /* Search for the value in the tree */
    search_tree(root, value);

    return 0;
}

/* Displays the binary search tree using ASCII characters */
void display_tree(bst_node_t *root, int depth, int pos, int search_value) {
    /* Check if we have reached the end of the tree */
    if (root == NULL) {
        return;
    }

    /* Calculate the absolute position of the node */
    int abs_pos = pos;
    for (int i = 0; i < depth; i++) {
        abs_pos += (1 << (MAX_DEPTH - i - 1));
    }

    /* Display the left subtree */
    display_tree(root->left, depth + 1, pos - (1 << (MAX_DEPTH - depth - 1)), search_value);

    /* Display the current node */
    if (search_value == root->value) {
        /* Highlight the node if it matches the search value */
        printf("\033[1;31m%d\033[0m", root->value);
    } else {
        printf("%d", root->value);
    }
    printf("(%d-%d)", depth, abs_pos);
    if (root->left == NULL && root->right == NULL) {
        printf("  *");  /* Leaf node */
    }
    printf("\n");

    /* Display the right subtree */
    display_tree(root->right, depth + 1, pos + (1 << (MAX_DEPTH - depth - 1)), search_value);
}

/* Searches for a value in the binary search tree */
void search_tree(bst_node_t *root, int value) {
    bst_node_t *current_node = root;

    /* Search for the value in the tree */
    while (true) {
        if (current_node == NULL) {
            /* Value not found */
            printf("Value %d does not exist in the tree\n", value);
            break;
        } else if (value == current_node->value) {
            /* Value found */
            printf("Value %d found in the tree\n", value);
            display_tree(root, 0, 0, value);
            break;
        } else if (value < current_node->value) {
            /* Go left in the subtree */
            printf("%d -> ", current_node->value);
            current_node = current_node->left;
        } else {
            /* Go right in the subtree */
            printf("%d -> ", current_node->value);
            current_node = current_node->right;
        }
    }
}