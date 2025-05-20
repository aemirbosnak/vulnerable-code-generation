//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include <stdio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }

    if (data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

void inOrder(struct Node* node) {
    if (node!= NULL) {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

int main() {
    struct Node* root = NULL;
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 1);
    insert(root, 20);
    insert(root, 8);
    insert(root, 12);
    insert(root, 4);
    insert(root, 7);
    insert(root, 18);
    insert(root, 14);
    insert(root, 9);
    insert(root, 22);
    insert(root, 19);
    insert(root, 21);
    insert(root, 6);
    insert(root, 3);
    insert(root, 13);
    insert(root, 2);

    printf("Inorder traversal of the tree is: ");
    inOrder(root);
    printf("\n");

    int search_value = 20;
    struct Node* node = root;

    while (node!= NULL) {
        if (node->data == search_value)
            printf("%d found at %d\n", search_value, node->data);
        if (node->data < search_value)
            node = node->right;
        else
            node = node->left;
    }

    return 0;
}