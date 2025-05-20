//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a binary search tree node
struct Node {
    char* key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(char* key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = strdup(key);
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new key into the binary search tree
struct Node* insert(struct Node* node, char* key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);
    
    // Otherwise, recur down the tree
    if (strcmp(key, node->key) < 0)
        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) > 0)
        node->right = insert(node->right, key);
    
    // return the unchanged node pointer
    return node;
}

// Function to print the tree in-order
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%s\n", root->key);
        inOrder(root->right);
    }
}

// Function to search for a key in the binary search tree
struct Node* search(struct Node* root, char* key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || strcmp(root->key, key) == 0)
        return root;

    // Key is greater than root's key
    if (strcmp(key, root->key) > 0)
        return search(root->right, key);
    
    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to free the memory allocated for the tree
void freeTree(struct Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->key);
        free(root);
    }
}

// Function to simulate the collapsing world
void survivalTip() {
    printf("In this post-apocalyptic world, knowledge is survival. Here are some burnt reminders:\n");
    printf("1. Always store food in a dry place.\n");
    printf("2. Keep your weapons sharpened and ready.\n");
    printf("3. Trust no one, but share the knowledge of survival.\n");
}

int main() {
    struct Node* root = NULL;

    // In this dark era, the code represents the only form of guidance
    char* resources[] = {
        "Water",
        "Food",
        "Fire",
        "Shelter",
        "Medicine",
        "Weapons",
        "Tools",
        "Clothing",
        "Communication",
        "Navigation"
    };

    // Inserting resources into the tree
    for (int i = 0; i < sizeof(resources) / sizeof(resources[0]); i++) {
        root = insert(root, resources[i]);
    }

    // Displaying the tree
    printf("Survival Resources:\n");
    inOrder(root);
    
    // Searching for specific resource in the bleak landscape
    char searchKey[20];
    printf("\nWhich resource do you wish to search for? ");
    fgets(searchKey, sizeof(searchKey), stdin);
    searchKey[strcspn(searchKey, "\n")] = 0; // Remove newline
    
    struct Node* found = search(root, searchKey);
    if (found) {
        printf("Found: %s! Use it wisely.\n", found->key);
    } else {
        printf("Resource '%s' not found. Keep searching, survival depends on it.\n", searchKey);
    }
    
    survivalTip();
    
    // Freeing the allocated memory
    freeTree(root);
    return 0;
}