//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to insert a node at the beginning of the linked list
void insert(Node **head_ref, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to delete a node from the linked list
void delete_node(Node **head_ref, int data) {
    Node *current = *head_ref;
    Node *prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the list\n");
        return;
    }

    if (prev == NULL) {
        *head_ref = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Function to search for an element in the linked list
int search(Node *head, int data) {
    Node *current = head;

    while (current!= NULL && current->data!= data) {
        current = current->next;
    }

    if (current == NULL) {
        return -1;
    }

    return 1;
}

// Function to print the linked list
void print_list(Node *head) {
    Node *current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("Linked list: ");
    print_list(head);

    delete_node(&head, 3);
    printf("\n");

    printf("Linked list after deleting 3: ");
    print_list(head);

    int data = 5;
    if (search(head, data) == 1) {
        printf("%d found in the list\n", data);
    } else {
        printf("%d not found in the list\n", data);
    }

    return 0;
}