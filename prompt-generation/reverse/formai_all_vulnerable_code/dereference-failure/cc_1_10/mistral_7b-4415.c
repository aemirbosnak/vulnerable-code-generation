//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node {
    char name[30];
    int age;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(char* name, int age) {
    Node* new = (Node*) malloc(sizeof(Node));
    strcpy(new->name, name);
    new->age = age;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node* insert(Node* root, char* name, int age) {
    if (root == NULL) {
        root = newNode(name, age);
    } else if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, age);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, age);
    }
    return root;
}

void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%s (%d years)\n", root->name, root->age);
        printInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    char names[10][30] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Henry", "Isabella", "Jack"};
    int ages[10] = {25, 32, 28, 45, 30, 41, 35, 51, 22, 29};

    for (int i = 0; i < 10; i++) {
        root = insert(root, names[i], ages[i]);
    }

    printf("Binary search tree in order:\n");
    printInOrder(root);

    return 0;
}