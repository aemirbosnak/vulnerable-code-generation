//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 100 // define a constant for the maximum value a node will store

// define a struct for a binary tree node
typedef struct TreeNode {
    int value; // the value stored in the node
    struct TreeNode * left; // pointer to the left child node
    struct TreeNode * right; // pointer to the right child node
} TreeNode;

// create a new binary tree node
TreeNode * createNode(int value) {
    TreeNode * node = (TreeNode *) malloc(sizeof(TreeNode)); // allocate memory for the new node
    node->value = value; // assign the given value to the node
    node->left = NULL; // set the left child to NULL
    node->right = NULL; // set the right child to NULL
    return node; // return the new node
}

// insert a new node into the binary tree in a random location
void insertNode(TreeNode * root, int value) {
    if (root == NULL) { // if the root node is NULL, create a new node with the given value and set it as the root
        root = createNode(value);
    } else { // otherwise, randomly choose to add the new node to the left or right subtree
        int direction = rand() % 2; // generate a random number, if it's even, add to the left, if it's odd, add to the right
        if (direction == 0) { // if adding to the left
            if (root->left == NULL) { // if the left child is NULL, create a new node with the given value and set it as the left child
                root->left = createNode(value);
            } else { // otherwise, recursively call the insert function on the left child
                insertNode(root->left, value);
            }
        } else { // if adding to the right
            if (root->right == NULL) { // if the right child is NULL, create a new node with the given value and set it as the right child
                root->right = createNode(value);
            } else { // otherwise, recursively call the insert function on the right child
                insertNode(root->right, value);
            }
        }
    }
}

// display the binary tree using an immersive visualization
void displayTree(TreeNode * root, int depth) {
    if (root == NULL) { // if the node is NULL, do nothing
        return;
    } else { // otherwise, recursively display the left and right subtrees
        displayTree(root->right, depth + 1); // display the right subtree
        for (int i = 0; i < depth; i++) { // print out a number of spaces equal to the depth of the node
            printf("   ");
        }
        printf("%d\n", root->value); // print out the value of the node
        displayTree(root->left, depth + 1); // display the left subtree
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    TreeNode * root = createNode(rand() % MAX_VALUE); // create the root node with a random value
    
    int numNodes = rand() % 10 + 10; // generate a random number of nodes to insert into the tree
    for (int i = 0; i < numNodes; i++) { // insert the nodes
        int value = rand() % MAX_VALUE; // generate a random value for the node
        insertNode(root, value); // insert the node into the binary tree
    }
    
    displayTree(root, 0); // display the binary tree using the immersive visualization
    
    return 0; // exit the program
}