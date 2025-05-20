//FormAI DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_at_beginning(struct node **head, int new_data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void insert_at_end(struct node **head, int new_data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;
}

void insert_after(struct node **head, int key, int new_data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    struct node *temp = *head;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the linked list\n", key);
        return;
    }

    new_node->data = new_data;
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_node(struct node **head, int key) {
    struct node *temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the linked list\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void print_list(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");
}

int main() {
    struct node *head = NULL;

    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 1);

    printf("Linked List after inserting at beginning: ");
    print_list(head);

    insert_at_end(&head, 4);
    insert_at_end(&head, 5);
    insert_at_end(&head, 6);

    printf("Linked List after inserting at end: ");
    print_list(head);

    insert_after(&head, 3, 7);
    insert_after(&head, 6, 8);

    printf("Linked List after inserting after a key: ");
    print_list(head);

    delete_node(&head, 1);
    delete_node(&head, 4);
    delete_node(&head, 8);

    printf("Linked List after deleting a node: ");
    print_list(head);

    return 0;
}