//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// A node in the BST, like a brave knight guarding its data
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Our BST, a castle of knowledge, with a noble knight at the helm
typedef struct bst {
    Node *root;
} BST;

// A new knight, eager to defend the realm
Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Inserting a new knight into the realm
Node *insert_node(Node *root, int data) {
    if (!root) return create_node(data);
    if (data < root->data) root->left = insert_node(root->left, data);
    else root->right = insert_node(root->right, data);
    return root;
}

// Finding a knight in the realm
Node *find_node(Node *root, int data) {
    if (!root) return NULL;
    if (root->data == data) return root;
    if (data < root->data) return find_node(root->left, data);
    return find_node(root->right, data);
}

// Traversing the realm, a grand procession to behold
void inorder_traversal(Node *root) {
    if (!root) return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int main() {
    // Our magnificent kingdom, a BST of wisdom
    BST kingdom;
    kingdom.root = NULL;

    // Adding valiant knights to the realm
    kingdom.root = insert_node(kingdom.root, 50);
    kingdom.root = insert_node(kingdom.root, 30);
    kingdom.root = insert_node(kingdom.root, 20);
    kingdom.root = insert_node(kingdom.root, 40);
    kingdom.root = insert_node(kingdom.root, 70);
    kingdom.root = insert_node(kingdom.root, 60);
    kingdom.root = insert_node(kingdom.root, 80);

    // Searching for a noble knight
    Node *found_knight = find_node(kingdom.root, 40);
    if (found_knight) printf("\nFound knight with data %d\n", found_knight->data);
    else printf("\nKnight not found within the realm\n");

    // Unveiling the kingdom's secrets
    printf("\nThe knights stand in this order:\n");
    inorder_traversal(kingdom.root);
    printf("\n");

    return 0;
}