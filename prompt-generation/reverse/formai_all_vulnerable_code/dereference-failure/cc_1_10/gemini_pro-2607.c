//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void insertNode(struct Node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    struct Node *temp = *root;
    while (1) {
        if (data < temp->data) {
            if (temp->left == NULL) {
                temp->left = createNode(data);
                break;
            } else {
                temp = temp->left;
            }
        } else if (data > temp->data) {
            if (temp->right == NULL) {
                temp->right = createNode(data);
                break;
            } else {
                temp = temp->right;
            }
        } else {
            printf("Duplicate data value ignored.\n");
            break;
        }
    }
}

struct Node *searchNode(struct Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }

    while (1) {
        if (data < root->data) {
            root = root->left;
        } else if (data > root->data) {
            root = root->right;
        } else {
            return root;
        }

        if (root == NULL) {
            return NULL;
        }
    }
}

void deleteNode(struct Node **root, int data) {
    struct Node *temp = *root;
    struct Node *parent = NULL;

    while (1) {
        if (data < temp->data) {
            parent = temp;
            temp = temp->left;
        } else if (data > temp->data) {
            parent = temp;
            temp = temp->right;
        } else {
            break;
        }

        if (temp == NULL) {
            printf("Node not found.\n");
            return;
        }
    }

    if (temp->left == NULL && temp->right == NULL) {
        if (parent == NULL) {
            *root = NULL;
        } else if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }

        free(temp);
    } else if (temp->left == NULL) {
        if (parent == NULL) {
            *root = temp->right;
        } else if (parent->left == temp) {
            parent->left = temp->right;
        } else {
            parent->right = temp->right;
        }

        free(temp);
    } else if (temp->right == NULL) {
        if (parent == NULL) {
            *root = temp->left;
        } else if (parent->left == temp) {
            parent->left = temp->left;
        } else {
            parent->right = temp->left;
        }

        free(temp);
    } else {
        struct Node *successor = temp->right;
        struct Node *successorParent = temp;

        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        temp->data = successor->data;

        if (successorParent == temp) {
            successorParent->right = successor->right;
        } else {
            successorParent->left = successor->right;
        }

        free(successor);
    }
}

void inOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node *root = NULL;

    // Insert some nodes into the BST
    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 2);
    insertNode(&root, 7);
    insertNode(&root, 12);
    insertNode(&root, 20);

    // Search for a node in the BST
    struct Node *foundNode = searchNode(root, 12);
    if (foundNode != NULL) {
        printf("Node found: %d\n", foundNode->data);
    } else {
        printf("Node not found.\n");
    }

    // Delete a node from the BST
    deleteNode(&root, 10);

    // Traverse the BST in various orders
    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}