//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int age;
    int height;
    struct node* left;
    struct node* right;
} node;

node* create_node(char name[], int age, int height) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->height = height;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node* root, char name[], int age, int height) {
    if (root == NULL) {
        root = create_node(name, age, height);
        return;
    }
    if (age < root->age) {
        insert_node(root->left, name, age, height);
    } else if (age > root->age) {
        insert_node(root->right, name, age, height);
    } else {
        printf("Duplicate entry for %s\n", name);
    }
}

void inorder_traversal(node* root) {
    if (root!= NULL) {
        inorder_traversal(root->left);
        printf("%s %d %d\n", root->name, root->age, root->height);
        inorder_traversal(root->right);
    }
}

int main() {
    node* root = NULL;
    char name[50];
    int age, height;

    printf("Enter name, age and height of the first person:\n");
    scanf("%s %d %d", name, &age, &height);
    root = create_node(name, age, height);

    printf("Enter name, age and height of the second person:\n");
    scanf("%s %d %d", name, &age, &height);
    insert_node(root, name, age, height);

    printf("Enter name, age and height of the third person:\n");
    scanf("%s %d %d", name, &age, &height);
    insert_node(root, name, age, height);

    printf("Inorder traversal:\n");
    inorder_traversal(root);

    return 0;
}