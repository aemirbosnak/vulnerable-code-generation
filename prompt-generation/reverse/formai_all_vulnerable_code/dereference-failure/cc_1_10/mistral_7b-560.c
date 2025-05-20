//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char symbol;
    int count;
    struct Node *left, *right;
} Node;

Node* createNode(char symbol) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->symbol = symbol;
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node** root, char symbol) {
    if (*root == NULL) {
        *root = createNode(symbol);
        return;
    }

    if (tolower(symbol) < tolower((*root)->symbol)) {
        insertNode(&(*root)->left, symbol);
    } else {
        insertNode(&(*root)->right, symbol);
    }
}

Node* buildTree(char* text) {
    Node* root = NULL;

    for (int i = 0; text[i] != '\0'; i++) {
        insertNode(&root, text[i]);
    }

    return root;
}

void printTree(Node* root, int depth) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, depth + 1);

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("%c (%d)\n", root->symbol, root->count);

    printTree(root->left, depth + 1);
}

void generateArt(Node* root, int height, char art[][21]) {
    if (root == NULL) {
        return;
    }

    generateArt(root->left, height - 1, art);

    for (int i = height - root->count; i > 0; i--) {
        art[height][i] = root->symbol;
        art[height - 1][i] = root->symbol;
    }

    generateArt(root->right, height - 1, art);
}

int main() {
    char text[100] = "Your text here!";
    Node* tree = buildTree(text);
    int height = 1 + (strlen(text) >> 1);
    char art[height][21];

    printf("Text: %s\n", text);
    printf("Tree:\n");
    printTree(tree, 0);

    generateArt(tree, height, art);

    printf("\nASCII Art:\n");
    for (int i = height; i > 0; i--) {
        for (int j = 0; j < 21; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    free(tree);
    return 0;
}