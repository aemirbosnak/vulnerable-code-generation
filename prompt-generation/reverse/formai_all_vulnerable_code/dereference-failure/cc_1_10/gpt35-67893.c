//FormAI DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} typedef Node;

Node* create_node(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert_node(Node* root, int value) {
    if(!root)
        return create_node(value);

    if(value < root->value)
        root->left = insert_node(root->left, value);
    else if(value > root->value)
        root->right = insert_node(root->right, value);
    
    return root;
}

Node* search_node(Node* root, int value) {
    if(!root || root->value == value)
        return root;
    
    if(value < root->value)
        return search_node(root->left, value);
    
    return search_node(root->right, value);
}

void print_tree(Node* root) {
    if(!root)
        return;
    
    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
}

void display_menu() {
    printf("\n\n1. Insert a node");
    printf("\n2. Search for a node");
    printf("\n3. Display the tree");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

int main() {
    Node* root = NULL;
    int choice, value;
    Node* result;

    do {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &value);
                root = insert_node(root, value);
                break;
            case 2:
                printf("\nEnter the value to search for: ");
                scanf("%d", &value);
                result = search_node(root, value);
                if(result)
                    printf("\nValue found: %d", result->value);
                else
                    printf("\nValue not found.");
                break;
            case 3:
                printf("\n\nBinary tree elements: ");
                print_tree(root);
                break;
            case 4:
                printf("\nExiting.");
                break;
            default:
                printf("\nInvalid choice.");
        }
    } while(choice != 4);

    return 0;
}