//FormAI DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* node, int data) {
    if (node == NULL) {
        return create_node(data);
    } else if (data < node->data) {
        node->left = insert_node(node->left, data);
    } else {
        node->right = insert_node(node->right, data);
    }
    return node;
}

Node* search_node(Node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    } else if (data < node->data) {
        return search_node(node->left, data);
    } else {
        return search_node(node->right, data);
    }
}

void print_tree(Node* node) {
    if (node != NULL) {
        print_tree(node->left);
        printf("%d ", node->data);
        print_tree(node->right);
    }
}

int main() {
    Node* root = NULL;
    int choice = 0;
    int data = 0;
    Node* search_res;
    do {
        printf("Welcome to the Binary search tree program\n");
        printf("1.Insert Node\n");
        printf("2.Search Node\n");
        printf("3.Print Tree\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert:");
                scanf("%d", &data);
                root = insert_node(root, data);
                printf("Data inserted successfully!\n");
                break;
            case 2:
                printf("Enter data to search:");
                scanf("%d", &data);
                search_res = search_node(root, data);
                if (search_res == NULL) {
                    printf("Data not found\n");
                } else {
                    printf("Data found\n");
                }
                break;
            case 3:
                printf("Printing tree:\n");
                print_tree(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while (choice != 4);
    return 0;
}