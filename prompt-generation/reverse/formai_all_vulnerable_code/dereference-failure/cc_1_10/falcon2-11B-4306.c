//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void create_tree(struct node** root) {
    int num_nodes;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &num_nodes);

    struct node* current = NULL;
    for (int i = 0; i < num_nodes; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;

        if (i == 0) {
            current = new_node;
        } else if (data < current->data) {
            new_node->left = current;
            current = new_node;
        } else {
            new_node->right = current;
            current = new_node;
        }
    }
}

int main() {
    struct node* root = NULL;
    create_tree(&root);

    printf("Enter data to search for: ");
    int data;
    scanf("%d", &data);

    struct node* current = root;
    while (current!= NULL) {
        if (data == current->data) {
            printf("Data found at node %d\n", current->data);
            break;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return 0;
}