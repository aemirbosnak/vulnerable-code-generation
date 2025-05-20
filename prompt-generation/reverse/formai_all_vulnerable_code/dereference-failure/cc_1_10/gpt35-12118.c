//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>

// Define a struct for the node of a linked list
struct Node{
    int data;
    struct Node* next;
};

// Display linked list using arrow symbols to indicate pointer references
void displayLinkedList(struct Node* head){
    struct Node* current = head;
    while(current){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Define a struct for a binary tree node
struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Display binary tree using ASCII graphics
void displayBinaryTree(struct TreeNode* root, int level){
    if(root == NULL){
        return;
    }
    displayBinaryTree(root->right, level+1);
    for(int i=0; i<level; i++){
        printf("      ");
    }
    printf("%d\n", root->data);
    displayBinaryTree(root->left, level+1);
}

int main(){
    // Example usage
    printf("Linked List:\n");
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;
    displayLinkedList(head);

    printf("\nBinary Tree:\n");
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->data = 1;
    root->left = malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    displayBinaryTree(root, 0);
    return 0;
}