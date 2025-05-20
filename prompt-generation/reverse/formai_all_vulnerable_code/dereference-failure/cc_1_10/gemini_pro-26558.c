//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Our binary search tree node, a bastion of knowledge
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// The mighty BST, a guardian of secrets
typedef struct BST {
    Node *root;
} BST;

// Our sorcerer, conjuring nodes from thin air
Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    if (!node) {
        printf("Memory imp, begone!\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// A valiant attempt to conquer the BST, one node at a time
void insertNode(BST *tree, int data) {
    Node *curr = tree->root;
    Node *prev = NULL;

    while (curr) {
        prev = curr;
        if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    Node *newNode = createNode(data);
    if (!tree->root) {
        tree->root = newNode;
    } else if (data < prev->data) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }
}

// A noble quest to find the secret of the tree, given a key
Node* searchNode(BST *tree, int key) {
    Node *curr = tree->root;
    while (curr) {
        if (key == curr->data) {
            return curr;
        } else if (key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return NULL;
}

// A somber task, removing a fallen hero from the BST
void deleteNode(BST *tree, int key) {
    Node *curr = tree->root;
    Node *prev = NULL;

    while (curr) {
        if (key == curr->data) {
            // Found the node, now banish it from the realm!
            if (!curr->left && !curr->right) {
                // No heirs, simply remove it
                if (prev) {
                    if (prev->left == curr) {
                        prev->left = NULL;
                    } else {
                        prev->right = NULL;
                    }
                } else {
                    // The king is dead, long live the new king!
                    tree->root = NULL;
                }
                free(curr);
            } else if (!curr->left) {
                // One heir to the left
                if (prev) {
                    if (prev->left == curr) {
                        prev->left = curr->right;
                    } else {
                        prev->right = curr->right;
                    }
                } else {
                    tree->root = curr->right;
                }
                free(curr);
            } else if (!curr->right) {
                // One heir to the right
                if (prev) {
                    if (prev->left == curr) {
                        prev->left = curr->left;
                    } else {
                        prev->right = curr->left;
                    }
                } else {
                    tree->root = curr->left;
                }
                free(curr);
            } else {
                // Two heirs, find the successor
                Node *successor = curr->right;
                Node *succPrev = curr;
                while (successor->left) {
                    succPrev = successor;
                    successor = successor->left;
                }

                // Replace the current node with its successor
                curr->data = successor->data;

                // Remove the successor from its original place
                if (succPrev->left == successor) {
                    succPrev->left = successor->right;
                } else {
                    succPrev->right = successor->right;
                }
                free(successor);
            }
            break;
        } else if (key < curr->data) {
            prev = curr;
            curr = curr->left;
        } else {
            prev = curr;
            curr = curr->right;
        }
    }
}

// An ancient ritual to traverse the BST, revealing its secrets
void inorderTraversal(Node *root) {
    if (!root) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main(void) {
    // Our beloved binary search tree, a realm of hidden treasures
    BST myTree;
    myTree.root = NULL;

    // Inserting secrets into the tree, one by one
    insertNode(&myTree, 10);
    insertNode(&myTree, 5);
    insertNode(&myTree, 15);
    insertNode(&myTree, 3);
    insertNode(&myTree, 7);
    insertNode(&myTree, 12);
    insertNode(&myTree, 17);

    // Searching for a hidden treasure, a key to untold riches
    int key = 7;
    Node *foundNode = searchNode(&myTree, key);
    if (foundNode) {
        printf("Eureka! Treasure found: %d\n", foundNode->data);
    } else {
        printf("Alas, treasure not found: %d\n", key);
    }

    // Removing a cursed artifact from the tree, breaking its dark spell
    key = 12;
    deleteNode(&myTree, key);
    printf("Cursed artifact removed: %d\n", key);

    // Unveiling the secrets of the tree, one by one
    printf("Inorder traversal: ");
    inorderTraversal(myTree.root);
    printf("\n");

    return 0;
}