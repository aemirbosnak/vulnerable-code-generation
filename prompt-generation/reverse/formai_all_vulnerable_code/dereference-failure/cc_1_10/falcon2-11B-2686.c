//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a node in the BST
struct node {
    char word[50];
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* create_node(char word[], struct node *left, struct node *right) {
    struct node *node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->word, word);
    node->left = left;
    node->right = right;
    return node;
}

// Function to insert a node into the BST
struct node* insert(struct node *root, char word[]) {
    if (root == NULL) {
        root = create_node(word, NULL, NULL);
        return root;
    }
    else if (strcmp(root->word, word) < 0) {
        root->left = insert(root->left, word);
    }
    else if (strcmp(root->word, word) > 0) {
        root->right = insert(root->right, word);
    }
    return root;
}

// Function to print the BST in pre-order traversal
void print_preorder(struct node *root) {
    if (root!= NULL) {
        printf("%s ", root->word);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

int main() {
    // Open the input file
    FILE *fp = fopen("index.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Create the root node
    struct node *root = NULL;

    // Read the file line by line
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Extract the first word from the line
        char *word = strtok(line, " ");
        char *word_copy = strdup(word);

        // Insert the word into the BST
        root = insert(root, word_copy);

        // Free the memory used by the word
        free(word_copy);
    }

    // Print the indexed entries in sorted order
    print_preorder(root);

    // Free the memory used by the root node
    free(root);

    // Close the input file
    fclose(fp);

    return 0;
}