//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
struct Node* search(struct Node* root, int data);
struct Node* minValueNode(struct Node* node);
struct Node* deleteNode(struct Node* root, int data);
void inOrder(struct Node* root);
void preOrder(struct Node* root);
void postOrder(struct Node* root);
void freeTree(struct Node* root);

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n*** Binary Search Tree Menu ***\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. In-Order Traversal\n");
        printf("5. Pre-Order Traversal\n");
        printf("6. Post-Order Traversal\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Inserted %d into the BST.\n", data);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("Found %d in the BST.\n", data);
                } else {
                    printf("%d not found in the BST.\n", data);
                }
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Deleted %d from the BST.\n", data);
                break;
            case 4:
                printf("In-Order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-Order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Post-Order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 7:
                freeTree(root);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}