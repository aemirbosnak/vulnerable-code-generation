//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define TREE_SYMBOL '*'
#define SPACE_SYMBOL ' '

typedef struct TreeNode {
    char symbol;
    int height;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(char symbol, int height) {
    TreeNode *newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->symbol = symbol;
    newNode->height = height;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(TreeNode **root, TreeNode *newNode) {
    if (*root == NULL) {
        *root = newNode;
    } else {
        if (newNode->height < (*root)->height) {
            if ((*root)->left == NULL) {
                (*root)->left = newNode;
            } else {
                insertNode(&(*root)->left, newNode);
            }
        } else {
            if ((*root)->right == NULL) {
                (*root)->right = newNode;
            } else {
                insertNode(&(*root)->right, newNode);
            }
        }
    }
}

int getLineLength(char* line) {
    int length = 0;
    while (line[length] != '\0') {
        if (line[length] == '\n') {
            break;
        }
        length++;
    }
    return length;
}

void printTree(TreeNode *root, int space) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, space + 1);

    int i;
    for (i = space; i < space + root->height; i++) {
        printf("%c", SPACE_SYMBOL);
    }

    printf("%c\n", root->symbol);

    printTree(root->left, space + 1);
}

void readFileAndBuildTree(char* filename, TreeNode **root) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    char line[MAX_WIDTH];
    int currentLineLength;
    TreeNode *currentNode;

    while (fgets(line, sizeof(line), file) != NULL) {
        currentLineLength = getLineLength(line);

        int i;
        for (i = 0; i < currentLineLength; i++) {
            if (i > 0 && (line[i] != ' ' && line[i-1] != ' ')) {
                currentNode = createNode(line[i], i + 1);
                insertNode(root, currentNode);
            }
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    TreeNode *treeRoot = NULL;

    readFileAndBuildTree(argv[1], &treeRoot);

    int i;
    for (i = treeRoot->height; i > 0; i--) {
        printf("%c", SPACE_SYMBOL);
    }

    printTree(treeRoot, 0);

    return 0;
}