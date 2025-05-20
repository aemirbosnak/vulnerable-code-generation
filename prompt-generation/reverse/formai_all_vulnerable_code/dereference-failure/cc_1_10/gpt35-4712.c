//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>

int main() {
    printf("Wow, look at this data structure!\n\n");

    // Declare an array of numbers
    int nums[5] = {3, 7, 2, 9, 4};

    printf("Here are the elements in our array:\n");

    // Print out each element in the array
    for(int i = 0; i < 5; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n\nNow let's check out this linked list:\n\n");

    // Define a node structure for the linked list
    struct Node {
        int data;
        struct Node* next;
    };

    // Create the first node
    struct Node* head = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = NULL;

    // Navigate through the linked list and print out each node's data
    struct Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n\nAmazing! Now let's explore this binary tree:\n\n");

    // Define a node structure for the binary tree
    struct TreeNode {
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
    };

    // Create the root node and insert some child nodes
    struct TreeNode* root = NULL;
    struct TreeNode* leftChild = NULL;
    struct TreeNode* rightChild = NULL;

    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    leftChild = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    rightChild = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->data = 1;
    root->left = leftChild;
    root->right = rightChild;

    leftChild->data = 2;
    leftChild->left = NULL;
    leftChild->right = NULL;

    rightChild->data = 3;
    rightChild->left = NULL;
    rightChild->right = NULL;

    // Traverse the tree and print out each node's data
    printf("%d ", root->data);
    printf("%d ", root->left->data);
    printf("%d ", root->right->data);

    printf("\n\nWhat a spectacular display of data structures!"); 

    return 0;
}