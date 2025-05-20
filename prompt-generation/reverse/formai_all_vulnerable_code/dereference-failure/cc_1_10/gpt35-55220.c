//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int key;
    struct node_t *left;
    struct node_t *right;
} Node;

Node * new_node(int key) {
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node *node, int key) {
    if (key < node->key) {
        if (node->left != NULL) {
            insert(node->left, key);
        } else {
            node->left = new_node(key);
        }
    } else {
        if (node->right != NULL) {
            insert(node->right, key);
        } else {
            node->right = new_node(key);
        }
    }
}

Node * search(Node *node, int key) {
    if (node == NULL || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

int main(void) {
    printf("Welcome to the binary search tree program!\n");
    printf("Oh no, I have trouble remembering the name...\n");
    printf("What do I call this program again? Oh, right, BST!\n");
    printf("This program will insert some numbers into a binary search tree,\n");
    printf("and then search for a number to see if it is in the tree.\n");
    printf("Let's get started!\n");

    Node *root = NULL;
    int nums_to_insert[] = {2, 1, 3, 5, 4};
    int num_to_search = 4;

    // Insert the numbers into the tree
    printf("Inserting numbers into tree: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums_to_insert[i]);
        if (root == NULL) {
            root = new_node(nums_to_insert[i]);
        } else {
            insert(root, nums_to_insert[i]);
        }
    }
    printf("\n");

    // Search for a number in the tree
    Node *found_node = search(root, num_to_search);
    if (found_node != NULL) {
        printf("The number %d was found in the tree!\n", found_node->key);
    } else {
        printf("The number %d was not found in the tree.\n", num_to_search);
        printf("Looks like it's time to find a new tree to search in!\n");
    }

    printf("Thanks for using the BST program! Goodbye!\n");
    return 0;
}