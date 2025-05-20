//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
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

// Function to search for a value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// In-order traversal to print nodes in sorted order
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to find the minimum value in the BST
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void knightAdventure(Node* root) {
    int treasure;
    printf("Brave knight, enter treasure number to search for: ");
    scanf("%d", &treasure);
    
    if (search(root, treasure)) {
        printf("Hooray! The treasure %d is found!!!\n", treasure);
    } else {
        printf("Oh no! The treasure %d is not in the forest!\n", treasure);
    }

    printf("Knight is exploring the forest in order:\n");
    inOrderTraversal(root);
    printf("\n");
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Brave Knight's BST Adventure ---\n");
        printf("1. Insert a treasure (value)\n");
        printf("2. Search for a treasure (value)\n");
        printf("3. Delete a treasure (value)\n");
        printf("4. Display treasures in sorted order\n");
        printf("5. Exit\n");
        printf("Choose your quest: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter treasure value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Player inserted %d to adventure!\n", value);
                break;
            case 2:
                knightAdventure(root);
                break;
            case 3:
                printf("Enter treasure value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("The brave knight tried to delete %d from the forest!\n", value);
                break;
            case 4:
                printf("Treasures in the forest: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("The brave knight has completed the adventure! Farewell!\n");
                exit(0);
            default:
                printf("Invalid choice, brave knight! Try again.\n");
        }
    }
    return 0;
}