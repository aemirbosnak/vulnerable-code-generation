//FormAI DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// definition of a binary tree node
struct node {
   int data;
   struct node* left;
   struct node* right;
};

// insert a new node in the binary search tree
struct node* insert_node(struct node* root, int data) {
    if (root == NULL) {
        struct node* new_node = malloc(sizeof(struct node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

// search for a node in the binary search tree
struct node* search_node(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search_node(root->left, key);
    }

    return search_node(root->right, key);
}

// perform an inorder traversal of the binary search tree
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// perform a preorder traversal of the binary search tree
void preorder(struct node* root) { 
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// perform a postorder traversal of the binary search tree
void postorder(struct node* root) { 
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Operations\n");
        printf("-------------------------------\n");
        printf("1. Insert a new node\n");
        printf("2. Search for a node\n");
        printf("3. Traverse in inorder\n");
        printf("4. Traverse in preorder\n");
        printf("5. Traverse in postorder\n");
        printf("6. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                root = insert_node(root, data);
                printf("Node with data %d has been inserted successfully!\n", data);
                break;
            case 2:
                printf("Enter key to be searched: ");
                scanf("%d", &data);
                if (search_node(root, data) == NULL) {
                    printf("No node with key %d found!\n", data);
                } else {
                    printf("Node with key %d found!\n", data);
                }
                break;
            case 3:
                printf("Inorder traversal of the binary search tree:\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal of the binary search tree:\n");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal of the binary search tree:\n");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Thank you for using this program!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}