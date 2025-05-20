//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_CHAR 256

typedef struct node {
    char data[MAX_CHAR];
    struct node *left, *right;
} Node;

Node* create_node(const char* data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->left = new_node->right = NULL;
    return new_node;
}

bool is_empty(Node* node) {
    return node == NULL;
}

Node* insert(Node* root, const char* data) {
    if (is_empty(root))
        return create_node(data);

    int cmp_res = strcmp(data, root->data);
    if (cmp_res < 0)
        root->left = insert(root->left, data);
    else if (cmp_res > 0)
        root->right = insert(root->right, data);

    return root;
}

void inorder_traversal(Node* node) {
    if (!is_empty(node)) {
        inorder_traversal(node->left);
        printf("%s ", node->data);
        inorder_traversal(node->right);
    }
}

void print_menu() {
    printf("\n\n====== BINARY SEARCH TREE ======\n");
    printf("1. Insert a new word.\n");
    printf("2. Display the tree in inorder traversal.\n");
    printf("3. Exit.\n");
}

int main() {
    Node* root = NULL;
    char input[MAX_CHAR];
    int choice;

    while (true) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a word to insert: ");
                scanf("%s", input);
                root = insert(root, input);
                break;

            case 2:
                printf("Tree in inorder traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;

            case 3:
                free(root);
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}