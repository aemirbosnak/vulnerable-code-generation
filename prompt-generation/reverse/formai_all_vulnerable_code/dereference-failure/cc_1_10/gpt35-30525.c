//FormAI DATASET v1.0 Category: Computer Biology ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

/* Define the node structure */
struct node {
    int value;
    struct node *left;
    struct node *right;
};

/* Function to create a new node */
struct node *newNode(int value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Function that inserts a new node in the tree */
struct node *insertNode(struct node *node, int value) {
    if (node == NULL) {
        return newNode(value);
    }
    if (value < node->value) {
        node->left = insertNode(node->left, value);
    }
    else if (value > node->value) {
        node->right = insertNode(node->right, value);
    }
    return node;
}

/* Function that prints the binary search tree in order traversal */
void printTree(struct node *node) {
    if (node != NULL) {
        printTree(node->left);
        printf("%d ", node->value);
        printTree(node->right);
    }
}

/* Function that calculates the height of the binary search tree */
int calculateHeight(struct node *node) {
    if (node == NULL) {
        return 0;
    }
    else {
        int leftDepth = calculateHeight(node->left);
        int rightDepth = calculateHeight(node->right);

        if (leftDepth > rightDepth) {
            return(leftDepth + 1);
        }
        else {
            return(rightDepth + 1);
        }
    }
}

int main() {
    struct node *root = NULL;
    int n, value, i;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the value of node %d: ", i+1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("In order traversal of binary search tree: ");
    printTree(root);

    printf("\nThe height of the binary search tree is %d\n", calculateHeight(root));

    return 0;
}