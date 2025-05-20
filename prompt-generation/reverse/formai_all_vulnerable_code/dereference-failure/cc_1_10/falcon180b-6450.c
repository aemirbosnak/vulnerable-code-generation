//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure for a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the node structure for a binary tree
typedef struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
} TreeNode;

// Function to print a linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print a binary tree
void printBinaryTree(TreeNode* root) {
    if (root == NULL) {
        printf("Binary Tree is empty\n");
        return;
    }
    TreeNode* temp = root;
    printf("Binary Tree: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->left;
    }
    printf("\n");
}

// Function to create a linked list
Node* createLinkedList(int arr[], int size) {
    Node* head = NULL;
    Node* temp = NULL;
    for (int i = 0; i < size; i++) {
        temp = (Node*)malloc(sizeof(Node));
        temp->data = arr[i];
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        }
        else {
            Node* current = head;
            while (current->next!= NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }
    return head;
}

// Function to create a binary tree
TreeNode* createBinaryTree(int arr[], int size) {
    TreeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
        temp->data = arr[i];
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL) {
            root = temp;
        }
        else {
            TreeNode* current = root;
            while (current->data < arr[i]) {
                if (current->left == NULL) {
                    current->left = temp;
                    break;
                }
                else {
                    current = current->left;
                }
            }
            if (current->data == arr[i]) {
                current->right = temp;
            }
            else {
                current->left = temp;
            }
        }
    }
    return root;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    Node* linkedList = createLinkedList(arr1, size1);
    printf("Linked List created:\n");
    printLinkedList(linkedList);

    int arr2[] = {5, 4, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    TreeNode* binaryTree = createBinaryTree(arr2, size2);
    printf("Binary Tree created:\n");
    printBinaryTree(binaryTree);

    return 0;
}