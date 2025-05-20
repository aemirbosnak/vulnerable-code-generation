//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct node {
    char ch;
    int freq;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char ch) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->freq = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node* root, char* str) {
    Node* curr = root;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char ch = tolower(str[i]);
        if (curr->left == NULL) {
            curr->left = createNode(ch);
        } else if (curr->right == NULL) {
            curr->right = createNode(ch);
        } else if (ch < curr->left->ch) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    curr->freq++;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%c %d\n", root->ch, root->freq);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    root = createNode(str[0]);
    insert(root, str);

    printf("Inorder traversal of the trie:\n");
    inorder(root);

    return 0;
}