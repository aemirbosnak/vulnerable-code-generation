//LLAMA2-13B DATASET v1.0 Category: Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAX_WEIGHT 64

// Define a struct to represent a binary tree node
struct node {
    char letter; // character of the node
    int weight; // weight of the node
    struct node *left, *right; // left and right child nodes
};

// Function to create a new node
struct node* new_node(char letter, int weight) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->letter = letter;
    node->weight = weight;
    node->left = node->right = NULL;
    return node;
}

// Function to traverse the tree and print its contents
void traverse(struct node* root) {
    if (root == NULL) {
        printf("(null)\n");
        return;
    }
    printf("%c (%d) ", root->letter, root->weight);
    traverse(root->left);
    traverse(root->right);
    printf("\n");
}

// Function to build a binary tree from a string
struct node* build_tree(char* str) {
    struct node* root = NULL;
    int i = 0;
    while (str[i] != '\0') {
        char letter = str[i];
        int weight = 1; // default weight is 1
        if (letter == '(') {
            weight = get_weight(str, i); // get the weight of the node
            i++; // skip over the weight
        }
        struct node* node = new_node(letter, weight);
        if (root == NULL) {
            root = node; // set the root node
        } else {
            if (letter < root->letter) {
                root->left = node;
            } else {
                root->right = node;
            }
        }
        i++; // move to the next character
    }
    return root;
}

// Function to get the weight of a node
int get_weight(char* str, int i) {
    int weight = 1; // default weight is 1
    while (str[i] != ')' && str[i] != '\0') {
        if (str[i] == '*') {
            weight *= get_weight(str, i + 1); // recursively get the weight of the subtree
            i++; // skip over the weight
        }
        i++; // move to the next character
    }
    return weight;
}

int main() {
    char str[] = "((a*b)*c)*d";
    struct node* root = build_tree(str);
    traverse(root);
    return 0;
}