//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: single-threaded
#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct binary_tree {
    struct node *root;
};

struct binary_tree *create_bst(int arr[], int n) {
    struct binary_tree *bst = (struct binary_tree*)malloc(sizeof(struct binary_tree));
    struct node *root = NULL;

    for (int i = 0; i < n; i++) {
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = arr[i];
        new_node->left = NULL;
        new_node->right = NULL;

        if (root == NULL) {
            root = new_node;
        } else {
            struct node *current = root;

            while (current!= NULL) {
                if (arr[i] < current->data) {
                    if (current->left == NULL) {
                        current->left = new_node;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = new_node;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    bst->root = root;

    return bst;
}

void search_bst(struct binary_tree *bst, int key) {
    struct node *current = bst->root;

    while (current!= NULL) {
        if (current->data == key) {
            printf("Element found: %d\n", key);
            break;
        } else if (current->data < key) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
}

void print_bst(struct binary_tree *bst) {
    struct node *current = bst->root;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->right;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct binary_tree *bst = create_bst(arr, n);

    search_bst(bst, 4);
    print_bst(bst);

    return 0;
}