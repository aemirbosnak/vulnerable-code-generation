//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_data(Node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
        return root;
    }

    if (data < root->data) {
        root->left = insert_data(root->left, data);
    } else if (data > root->data) {
        root->right = insert_data(root->right, data);
    }

    return root;
}

Node* create_bst(int size, int range) {
    Node* root = NULL;
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        int data = rand() % range;
        root = insert_data(root, data);
    }

    return root;
}

int count_nodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int left_count = count_nodes(root->left);
    int right_count = count_nodes(root->right);

    return 1 + left_count + right_count;
}

int main() {
    int size, range;

    printf("Enter the size of the binary search tree: ");
    scanf("%d", &size);

    printf("Enter the range of data values: ");
    scanf("%d", &range);

    Node* root = create_bst(size, range);

    int nodes_count = count_nodes(root);

    printf("\nNumber of nodes in the binary search tree: %d\n", nodes_count);

    return 0;
}