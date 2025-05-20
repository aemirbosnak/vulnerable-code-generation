//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_DESC_LENGTH 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Node* createNode(const char* name, const char* description) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    strncpy(newNode->description, description, MAX_DESC_LENGTH);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

void insert(Tree* tree, const char* name, const char* description) {
    Node* newNode = createNode(name, description);
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }

    Node* current = tree->root;
    Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (strcmp(name, current->name) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (strcmp(name, parent->name) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

Node* search(Node* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }
    return search(root->right, name);
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("Name: %s, Description: %s\n", root->name, root->description);
        inOrder(root->right);
    }
}

// Cyberpunk: Display the details of nodes in a futuristic interface
void displayTree(Tree* tree) {
    printf("=== CyberNet Tree Display ===\n");
    if (tree->root == NULL) {
        printf("No data found.\n");
    } else {
        inOrder(tree->root);
    }
    printf("==============================\n");
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Tree* cyberTree = createTree();

    // Adding some entries with a cyberpunk theme
    insert(cyberTree, "Neon Dragon", "A glowing cybernetic beast roaming the sprawl.");
    insert(cyberTree, "Cyber Ninja", "A stealthy killer lurking in the shadows of the megacity.");
    insert(cyberTree, "Digital Shaman", "A hacker with the ability to navigate the net in spirit form.");
    insert(cyberTree, "Chrome Arm", "An advanced prosthetic arm with built-in weaponry.");
    insert(cyberTree, "Neural Interface", "A technology allowing direct interaction with machines.");

    // Display the tree in a futuristic manner
    displayTree(cyberTree);

    // Searching for a character
    const char* searchName = "Cyber Ninja";
    Node* foundNode = search(cyberTree->root, searchName);
    if (foundNode) {
        printf("Search Result: Found %s - %s\n", foundNode->name, foundNode->description);
    } else {
        printf("Search Result: %s not found in the net.\n", searchName);
    }

    // Free memory
    freeTree(cyberTree->root);
    free(cyberTree);
    
    return 0;
}