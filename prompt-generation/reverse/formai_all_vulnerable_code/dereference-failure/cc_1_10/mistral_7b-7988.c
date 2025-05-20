//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char ch;
    int count;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(char ch) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->ch = ch;
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node** root, char ch) {
    if (*root == NULL) {
        *root = newNode(ch);
    } else if (tolower(ch) < tolower((*root)->ch)) {
        insert(&((*root)->left), ch);
    } else if (tolower(ch) > tolower((*root)->ch)) {
        insert(&((*root)->right), ch);
    } else {
        (*root)->count++;
    }
}

void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, space + 1);

    for (int i = 0; i < space; i++) {
        putchar(' ');
    }

    putchar(root->ch);
    printf(" %d\n", root->count);

    printTree(root->left, space + 1);
}

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);

    Node* root = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        insert(&root, str[i]);
    }

    printTree(root, 0);

    return 0;
}