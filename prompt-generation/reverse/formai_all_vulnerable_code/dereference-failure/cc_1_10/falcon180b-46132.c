//Falcon-180B DATASET v1.0 Category: Recursive ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* left;
    struct node* right;
} node;

void create_tree(node* root, int depth) {
    if (depth > 0) {
        root = (node*)malloc(sizeof(node));
        root->data = rand() % MAX_SIZE;
        root->left = NULL;
        root->right = NULL;
        create_tree(root->left, depth - 1);
        create_tree(root->right, depth - 1);
    }
}

void print_tree(node* root, int space) {
    if (root!= NULL) {
        print_tree(root->right, space + 10);
        printf("\n");
        for (int i = 0; i < space; i++) {
            printf(" ");
        }
        printf("%d\n", root->data);
        print_tree(root->left, space + 10);
    }
}

void delete_tree(node* root) {
    if (root!= NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

int main() {
    srand(time(NULL));

    node* root = NULL;
    create_tree(root, 5);

    printf("Original tree:\n");
    print_tree(root, 0);

    delete_tree(root);

    printf("\nDeleted tree.\n");

    return 0;
}