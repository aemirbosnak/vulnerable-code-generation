//FormAI DATASET v1.0 Category: Binary search trees ; Style: puzzling
// Welcome to the Tree labyrinth!

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// The Tree itself
typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} Tree;

// Search the Tree labyrinth
int search_labyrinth(Tree* node, int val) {
    if (node == NULL) {
        return FALSE;
    }
    else if (node->data == val) {
        return TRUE;
    }
    else if (val < node->data) {
        return search_labyrinth(node->left, val);
    }
    else {
        return search_labyrinth(node->right, val);
    }
}

// Create the Tree labyrinth
Tree* create_labyrinth(int root_val) {
    Tree* root = (Tree*) malloc(sizeof(Tree));
    root->data = root_val;
    root->left = NULL;
    root->right = NULL;
    
    if (root_val == 42) {
        return root;
    }
    else {
        root->left = create_labyrinth(root_val - 1);
        root->right = create_labyrinth(root_val + 1);
    }
    return root;
}

// The entrance to the labyrinth
int main() {
    int key;
    Tree* maze = create_labyrinth(50);

    printf("Welcome to the Tree labyrinth! Your goal is to find the number 42.\n");
    printf("Enter a number to search the labyrinth: ");
    scanf("%d", &key);

    if (search_labyrinth(maze, key) == TRUE) {
        printf("Congratulations! You have found the number 42!\n");
    }
    else {
        printf("You have failed to find the number 42. Please try again.\n");
    }

    return 0;
}