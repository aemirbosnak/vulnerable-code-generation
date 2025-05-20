//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

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

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } 
    return search(root->right, data);
}

void visualize(Node* root, int space) {
    const int COUNT = 10;
    if (root == NULL) {
        return;
    }
    space += COUNT;
    visualize(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    visualize(root->left, space);
}

void clear(Node* root) {
    if (root == NULL) {
        return;
    }
    clear(root->left);
    clear(root->right);
    free(root);
}

void printMenu() {
    printf("\n=== BST Visualization Program ===\n");
    printf("1. Insert value\n");
    printf("2. Search value\n");
    printf("3. Visualize tree\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted!\n", value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* found = search(root, value);
                if (found) {
                    printf("Value %d found in the tree!\n", value);
                } else {
                    printf("Value %d not found!\n", value);
                }
                break;
            case 3:
                printf("\nCurrent BST Structure:\n");
                visualize(root, 0);
                break;
            case 4:
                clear(root);
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}