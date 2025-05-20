//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int age;
    struct Node *left, *right;
} Node;

Node *create_node(char name[], int age) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert(Node *root, Node *new_node) {
    if (root == NULL) {
        root = new_node;
        return root;
    }

    if (strcmp(new_node->name, root->name) < 0) {
        root->left = insert(root->left, new_node);
    } else if (strcmp(new_node->name, root->name) > 0) {
        root->right = insert(root->right, new_node);
    }

    return root;
}

Node *search(Node *root, char name[]) {
    if (root == NULL || strcmp(name, root->name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }

    return search(root->right, name);
}

void inorder_traversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%s (%d)\n", root->name, root->age);
    inorder_traversal(root->right);
}

int main() {
    Node *sherlock = create_node("Sherlock Holmes", 45);
    Node *watson = create_node("Dr. Watson", 35);
    Node *moriarty = create_node("Professor Moriarty", 55);
    Node *lestrade = create_node("Inspector Lestrade", 40);

    sherlock = insert(sherlock, watson);
    sherlock = insert(sherlock, moriarty);
    sherlock = insert(sherlock, lestrade);

    printf("Inquiries at 221B Baker Street:\n");
    inorder_traversal(sherlock);

    Node *victim = create_node("Mr. X", 30);
    Node *found = search(sherlock, "Mr. X");

    if (found != NULL) {
        printf("\nFound %s (%d) in the Baker Street Irregulars!\n", found->name, found->age);
        printf("Ask him some questions, Holmes!\n");
    } else {
        printf("\n%s (%d) is not in the Baker Street Irregulars.\n", victim->name, victim->age);
        printf("Perhaps another adventure awaits, Holmes!\n");
    }

    return 0;
}