//FormAI DATASET v1.0 Category: Database querying ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void display(struct node *node) {
    printf("%d ", node->data);
    if(node->next != NULL) {
        display(node->next);
    }
}

int search(struct node *node, int key) {
    if(node == NULL) {
        return 0;
    }
    if(node->data == key) {
        return 1;
    }
    return search(node->next, key);
}

int main() {
    struct node *head = NULL;
    int key = 5;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("Elements in the linked list are: ");
    display(head);

    if(search(head, key)) {
        printf("\n%d is present in the linked list.", key);
    } else {
        printf("\n%d is not present in the linked list.", key);
    }

    return 0;
}