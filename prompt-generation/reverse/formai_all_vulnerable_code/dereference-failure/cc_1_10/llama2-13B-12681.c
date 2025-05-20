//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEPTH 10
#define MAX_PATH 50

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

node* search(node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (root->value == target) {
        return root;
    }

    node* left = search(root->left, target);
    node* right = search(root->right, target);

    if (left != NULL && right != NULL) {
        return root;
    } else if (left != NULL) {
        return left;
    } else if (right != NULL) {
        return right;
    } else {
        return NULL;
    }
}

int main() {
    node* root = NULL;

    srand(time(NULL));

    for (int i = 0; i < MAX_PATH; i++) {
        int value = rand() % 10;
        node* new_node = (node*) malloc(sizeof(node));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;

        if (i == 0) {
            root = new_node;
        } else {
            node* current = root;
            while (current != NULL) {
                if (current->value == value) {
                    current->left = new_node;
                    break;
                }
                current = current->right;
            }
            if (current == NULL) {
                current = root;
                root = new_node;
            }
        }
    }

    node* found = search(root, 5);

    if (found != NULL) {
        printf("Found value: %d\n", found->value);
    } else {
        printf("Not found\n");
    }

    return 0;
}