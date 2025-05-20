//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int search(Node* root, int data) {
    if (root == NULL) {
        return -1;
    } else if (root->data == data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* root = NULL;

    for (int i = 0; i < size; i++) {
        root = insertNode(root, arr[i]);
    }

    int target;
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    int result = search(root, target);

    if (result == -1) {
        printf("Number not found.\n");
    } else {
        printf("Number found.\n");
    }

    return 0;
}