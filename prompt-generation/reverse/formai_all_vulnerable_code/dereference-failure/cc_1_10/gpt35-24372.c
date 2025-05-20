//FormAI DATASET v1.0 Category: Binary search trees ; Style: puzzling
/*
You are trying to solve a puzzle and the clues are hidden in a binary search tree. 
However, to unlock the clues, you must traverse the tree in a specific order. 
Once you have done so, the puzzle will be solved.

Here's the binary search tree:
             23
           /    \
          15     50
         / \     / \
        9  20  35  82
     
The order you must traverse the tree in is:
9, 35, 20, 50, 15, 82, 23

Good luck!

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

void print_puzzle_solved() {
    int i;
    char* message = "PUZZLE SOLVED";
    for(i = 0; i < 13; i++) {
        printf("%c", message[i]);
        usleep(350000);
    }
}

struct node* new_node(int item) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = item;
    node->left = node->right = NULL;
    return node;
}

void inorder_traversal(struct node* root) {
    if(root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

int main() {
    
    // Creating the binary search tree
    struct node* root = new_node(23);
    root->left = new_node(15);
    root->right = new_node(50);
    root->left->left = new_node(9);
    root->left->right = new_node(20);
    root->right->left = new_node(35);
    root->right->right = new_node(82);
    
    // Traverse the tree in the correct order to solve the puzzle
    inorder_traversal(root->left->left);
    inorder_traversal(root->right->left);
    inorder_traversal(root->left->right);
    inorder_traversal(root->right);
    inorder_traversal(root->left);
    inorder_traversal(root->right->right);
    inorder_traversal(root);
    
    // Puzzle solved
    print_puzzle_solved();
    
    return 0;
}