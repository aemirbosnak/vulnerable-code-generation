//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define the structure for the node in the binary search tree
typedef struct node
{
    char key;
    struct node* left;
    struct node* right;
} node;

// Define the function to search for a specific value in the binary search tree
node* search(node* root, char target)
{
    if (root == NULL || root->key == target)
    {
        return root;
    }
    if (root->key > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}

// Define the function to insert a new node into the binary search tree
node* insert(node* root, char value)
{
    if (root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->key = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (value < root->key)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->key)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// Define the function to print the binary search tree
void print_tree(node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->key);
    print_tree(root->left);
    print_tree(root->right);
}

// Define the main function
int main()
{
    node* root = NULL;
    char input[100];
    int i;

    // Create a binary search tree
    root = insert(root, 'a');
    insert(root, 'b');
    insert(root, 'c');
    insert(root, 'd');
    insert(root, 'e');
    insert(root, 'f');
    insert(root, 'g');
    insert(root, 'h');
    insert(root, 'i');
    insert(root, 'j');
    insert(root, 'k');
    insert(root, 'l');
    insert(root,'m');
    insert(root, 'n');
    insert(root, 'o');
    insert(root, 'p');
    insert(root, 'q');
    insert(root, 'r');
    insert(root,'s');
    insert(root, 't');
    insert(root, 'u');
    insert(root, 'v');
    insert(root, 'w');
    insert(root, 'x');
    insert(root, 'y');
    insert(root, 'z');

    // Print the binary search tree
    printf("\nBinary Search Tree: ");
    print_tree(root);

    // Search for a value in the binary search tree
    char target;
    printf("\nEnter a character to search for: ");
    fgets(input, sizeof(input), stdin);
    target = input[0];
    node* result = search(root, target);

    // Print the result of the search
    if (result == NULL)
    {
        printf("\nCharacter '%c' not found in the binary search tree.\n", target);
    }
    else
    {
        printf("\nCharacter '%c' found at position %d in the binary search tree.\n", target, result->key - 'a');
    }

    return 0;
}