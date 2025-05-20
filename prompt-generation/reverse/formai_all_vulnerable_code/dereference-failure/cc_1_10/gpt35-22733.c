//FormAI DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100 // Maximum length of input string

typedef struct treeNode {
    char data;
    struct treeNode* left;
    struct treeNode* right;
} TreeNode;

/* Function to create and initialize a new node */
TreeNode* newNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to build a binary tree from the given expression */
TreeNode* buildBinaryTree(char* expression) {
    int len = strlen(expression);
    TreeNode* root = NULL;
    TreeNode* nodeStack[len];
    int top = -1;

    for(int i=0; i<len; i++) {
        char ch = expression[i];

        if(ch == '(') {
            /* Push NULL to signify the left child is not yet determined */
            nodeStack[++top] = NULL;
        }
        else if(ch == ')') {
            /* Pop the parent node and link it to its children */
            TreeNode* right = nodeStack[top--];
            TreeNode* left = nodeStack[top--];
            nodeStack[top]->left = left;
            nodeStack[top]->right = right;
        }
        else if(ch >= 'a' && ch <= 'z') {
            /* Create a new node for the operand and push it to the stack */
            TreeNode* node = newNode(ch);
            nodeStack[++top] = node;
        }
        else {
            /* Create a new node for the operator and push it to the stack */
            TreeNode* node = newNode(ch);
            node->left = nodeStack[top];
            nodeStack[top] = node;
        }
    }

    root = nodeStack[0];
    return root;
}

/* Function to traverse the binary tree in pre-order fashion */
void preOrderTraversal(TreeNode* root) {
    if(root != NULL) {
        printf("%c", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    char input[MAX_INPUT];
    printf("Enter a mathematical expression in prefix notation: ");
    fgets(input, MAX_INPUT, stdin);
    input[strlen(input)-1] = '\0'; // Remove newline character
    TreeNode* root = buildBinaryTree(input);
    printf("\nTree visualization:\n\n");

    int levels = 0;
    /* Calculate the number of levels in the tree */
    TreeNode* temp = root;
    while(temp != NULL) {
        temp = temp->left;
        levels++;
    }
    levels--;

    char shape = 's';
    /* Iterate over each level of the tree */
    for(int i=0; i<=levels; i++) {
        /* Print the appropriate shape for the current level */
        switch(shape) {
            case 's':
                printf(" ");
                break;

            case 'l':
                printf("└");
                break;

            case 'r':
                printf("┌");
                break;

            case 'b':
                printf("─");
                break;

            default:
                printf(" ");
        }

        int nodesAtThisLevel = 1 << i; // Number of nodes at current level
        int nodesCounted = 0; // Used to track the number of nodes processed so far

        /* Iterate over each node at the current level */
        for(int j=0; j<nodesAtThisLevel; j++) {
            if(nodesCounted < nodesAtThisLevel) {
                /* Print the data of the node */
                if(i == 0) {
                    printf("%c", root->data);
                }
                else {
                    printf(" ");

                    /* Print the left child of the node if it exists */
                    if(root->left != NULL) {
                        printf("/");
                        shape = 'l';
                    }
                    else {
                        printf(" ");
                        shape = 's';
                    }

                    printf(" ");

                    /* Print the right child of the node if it exists */
                    if(root->right != NULL) {
                        printf("\\");
                        shape = 'r';
                    }
                    else {
                        printf(" ");
                        shape = 's';
                    }

                    printf(" ");
                    nodesCounted++;
                }

                /* Move to the next node at the current level */
                if(nodesCounted < nodesAtThisLevel) {
                    root = (shape == 'r') ? root->left : root->right;
                }
            }
        }
        printf("\n");
    }

    printf("\nPrefix expression traversal: ");
    preOrderTraversal(root);
    printf("\n");

    return 0;
}