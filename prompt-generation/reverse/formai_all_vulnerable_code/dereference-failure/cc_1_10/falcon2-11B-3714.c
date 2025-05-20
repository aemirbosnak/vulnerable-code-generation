//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void insert(struct Node **root, int key) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = key;
    if (*root == NULL) {
        *root = temp;
    } else {
        struct Node *current = *root;
        while (current!= NULL) {
            if (key < current->data) {
                if (current->left == NULL) {
                    current->left = temp;
                    break;
                } else {
                    current = current->left;
                }
            } else if (key > current->data) {
                if (current->right == NULL) {
                    current->right = temp;
                    break;
                } else {
                    current = current->right;
                }
            } else {
                // duplicate key, do nothing
                printf("Duplicate key found.\n");
                break;
            }
        }
    }
}

void inorder(struct Node *root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    inorder(root);

    return 0;
}