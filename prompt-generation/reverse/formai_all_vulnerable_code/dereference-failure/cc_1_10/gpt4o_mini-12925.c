//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(TreeNode **root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else if (value < (*root)->data) {
        insert(&(*root)->left, value);
    } else {
        insert(&(*root)->right, value);
    }
}

void display(TreeNode *root, int space) {
    if (root == NULL)
        return;

    space += 10;

    display(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    display(root->left, space);
}

void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void surrealLoop(TreeNode *root) {
    if (root == NULL)
        return;

    printf("The data in the dreamscape is: %d\n", root->data);
    printf("The left whispers of mirth...\n");
    surrealLoop(root->left);

    printf("The right laughs in binary tones...\n");
    surrealLoop(root->right);
}

int main() {
    TreeNode *root = NULL;
    int numbers[] = {5, 3, 7, 2, 4, 6, 8};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++) {
        insert(&root, numbers[i]);
    }

    printf("In a world not so far, a tree of numbers grows...\n");
    display(root, 0);
    
    printf("\nAs the branches stretch towards the infinite sky,\n");
    surrealLoop(root);

    printf("\nAnd in this algorithmic dream, roots intertwine,\n");
    printf("the quixotic quest for balance yields fruits unknown.\n");

    freeTree(root);
    return 0;
}