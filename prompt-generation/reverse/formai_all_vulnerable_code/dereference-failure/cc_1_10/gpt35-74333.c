//FormAI DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Structure for the node in the linked list
struct node {
    int data;
    struct node *next;
};

// Structure for the binary tree node
struct btNode {
    int data;
    struct btNode *left, *right;
};

// Function to create a new node for the linked list
struct node* createNode(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new node for the binary tree
struct btNode* createBTNode(int data) {
    struct btNode *newNode = (struct btNode*) malloc(sizeof(struct btNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node in the binary tree
void insertInBT(struct btNode **root, int data) {
    struct btNode *newNode = createBTNode(data);
    if (*root == NULL) {
        *root = newNode;
    }
    else {
        struct btNode *temp = *root;
        while (temp != NULL) {
            if (temp->data > data) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
}

// Function to print the linked list
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to print the binary tree
void printBT(struct btNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printBT(root->left);
    printBT(root->right);
}

// Main function to test the program
int main() {
    struct node *head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    printf("Linked List: ");
    printList(head);
    printf("\n");

    struct btNode *root = NULL;
    insertInBT(&root, 2);
    insertInBT(&root, 1);
    insertInBT(&root, 3);
    printf("Binary Tree: ");
    printBT(root);
    printf("\n");

    return 0;
}