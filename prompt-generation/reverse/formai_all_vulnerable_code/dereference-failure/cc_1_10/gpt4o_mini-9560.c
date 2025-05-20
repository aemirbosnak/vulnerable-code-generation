//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char clue[100];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char *clue) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->clue, clue);
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(struct Node **root, char *clue) {
    if (*root == NULL) {
        *root = createNode(clue);
    } else if (strcmp(clue, (*root)->clue) < 0) {
        insert(&((*root)->left), clue);
    } else {
        insert(&((*root)->right), clue);
    }
}

struct Node* search(struct Node *root, char *clue) {
    if (root == NULL || strcmp(root->clue, clue) == 0) {
        return root;
    } else if (strcmp(clue, root->clue) < 0) {
        return search(root->left, clue);
    } else {
        return search(root->right, clue);
    }
}

void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s\n", root->clue);
        inorderTraversal(root->right);
    }
}

void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void detectiveAdventure() {
    struct Node *clueTree = NULL;
    
    // Insert clues into the Binary Search Tree
    insert(&clueTree, "The butler did it");
    insert(&clueTree, "The clock struck twelve");
    insert(&clueTree, "A mysterious letter was found");
    insert(&clueTree, "The footprints led to the garden");
    insert(&clueTree, "A bloody handkerchief was located");
    
    printf("Sherlock's Clues in order:\n");
    inorderTraversal(clueTree);
    
    char choice[100];
    printf("Enter the clue you want to search for: ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0; // Remove the newline character

    struct Node *foundClue = search(clueTree, choice);
    if (foundClue != NULL) {
        printf("Clue found: %s\n", foundClue->clue);
    } else {
        printf("Clue not found. The detective must investigate further!\n");
    }

    freeTree(clueTree);
}

int main() {
    printf("Welcome to the Sherlock Holmes Binary Search Tree Adventure!\n");
    detectiveAdventure();
    return 0;
}