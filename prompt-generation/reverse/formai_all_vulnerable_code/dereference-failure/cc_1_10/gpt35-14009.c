//FormAI DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct student {
    int roll_no;
    char name[MAX];
    int marks;
};

typedef struct node {
    struct student data;
    struct node *left_child;
    struct node *right_child;
} Node;

Node *insert(Node *root, struct student data) {
    if (root == NULL) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = data;
        new_node->left_child = NULL;
        new_node->right_child = NULL;
        return new_node;
    }

    if (data.roll_no < root->data.roll_no) {
        root->left_child = insert(root->left_child, data);
    } else if (data.roll_no > root->data.roll_no) {
        root->right_child = insert(root->right_child, data);
    }

    return root;
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left_child);
    printf("Roll No: %d, Name: %s, Marks: %d\n", root->data.roll_no, root->data.name, root->data.marks);
    inorder(root->right_child);
}

int main() {
    Node *root = NULL;

    struct student s1 = {1, "John", 90};
    struct student s2 = {2, "Jane", 80};
    struct student s3 = {3, "Bob", 95};

    root = insert(root, s1);
    root = insert(root, s2);
    root = insert(root, s3);

    inorder(root);
    return 0;
}