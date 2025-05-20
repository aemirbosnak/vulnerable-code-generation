//FormAI DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert(struct node *root, int data) {
    if(root == NULL) {
        root = create_node(data);
        return root;
    }
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

struct node *search(struct node *root, int key) {
    if(root == NULL) return NULL; 
    else if(root->data == key) return root;
    else if(key <= root->data) return search(root->left, key);
    else return search(root->right, key);
}

void print_tree(struct node *root) {
    if(root == NULL) return;
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main(void) {

    struct node *root = NULL, *temp;
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 7);

    printf("Printing the Tree...\n");
    print_tree(root);

    int num;
    printf("\nEnter the value you want to search: ");
    scanf("%d", &num);

    temp = search(root, num);
    if(temp == NULL)
        printf("%d not found in the Tree\n", num);
    else
        printf("%d is present in the Tree\n", num);

    return 0;
}