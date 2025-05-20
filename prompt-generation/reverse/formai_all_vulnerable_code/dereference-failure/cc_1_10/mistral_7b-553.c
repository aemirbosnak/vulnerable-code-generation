//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH + 1];
    int strength;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(const char* name, int strength) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->strength = strength;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, const char* name, int strength) {
    if (root == NULL) {
        root = createNode(name, strength);
    } else if (strcasecmp(name, root->name) < 0) {
        root->left = insert(root->left, name, strength);
    } else {
        root->right = insert(root->right, name, strength);
    }

    return root;
}

Node* search(Node* root, const char* name) {
    if (root == NULL || strcasecmp(name, root->name) == 0) {
        return root;
    } else if (strcasecmp(name, root->name) < 0) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

void display(Node* root, int level) {
    if (root != NULL) {
        display(root->right, level + 1);
        printf("%*s%s: strength %d\n", level * 4, "", root->name, root->strength);
        display(root->left, level + 1);
    }
}

int main() {
    Node* tree = NULL;

    // Insert creatures into the binary search tree
    tree = insert(tree, "Dragon", 100);
    tree = insert(tree, "Unicorn", 80);
    tree = insert(tree, "Minotaur", 90);
    tree = insert(tree, "Griffin", 75);
    tree = insert(tree, "Phoenix", 95);
    tree = insert(tree, "Chimera", 85);
    tree = insert(tree, "Centaur", 70);

    // Display the binary search tree
    printf("Binary Search Tree:\n");
    display(tree, 0);

    // Search for a creature
    Node* unicorn = search(tree, "Unicorn");
    if (unicorn != NULL) {
        printf("\nFound Unicorn with strength %d\n", unicorn->strength);
    } else {
        printf("\nUnicorn not found\n");
    }

    return 0;
}