//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void displayList(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void changeToBinaryTree(struct node **head) {
    struct node *temp = *head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *right = temp->next;
    struct node *left = temp->next->next;

    temp->next = NULL;

    *head = temp;

    struct node *root = (struct node *)malloc(sizeof(struct node));
    if (root == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    root->data = temp->data;
    root->next = NULL;

    if (left!= NULL) {
        root->next = left;
    } else {
        printf("Left child is NULL!\n");
        return;
    }

    if (right!= NULL) {
        root->next = right;
    } else {
        printf("Right child is NULL!\n");
        return;
    }
}

int main() {
    struct node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    printf("Original list:\n");
    displayList(head);

    changeToBinaryTree(&head);

    printf("\nBinary tree:\n");
    struct node *current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}