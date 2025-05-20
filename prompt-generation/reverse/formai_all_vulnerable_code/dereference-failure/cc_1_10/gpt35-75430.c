//FormAI DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// define a structure for the linked list node
struct node {
    int data;
    struct node *next;
};

// function to print the linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// function to insert a node at the beginning
void push(struct node **head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// function to insert a node at the end
void append(struct node **head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// function to delete the first node
void pop(struct node **head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty\n");
        exit(1);
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// function to delete the last node
void delete_last(struct node **head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty\n");
        exit(1);
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *second_last = *head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}

// function to delete a node with given value
void delete_node(struct node **head, int value) {
    if (*head == NULL) {
        printf("Error: Linked list is empty\n");
        exit(1);
    }
    if ((*head)->data == value) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct node *current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Error: Node not found\n");
        return;
    }
    struct node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int main() {
    struct node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    append(&head, 3);
    append(&head, 4);
    printf("Linked list: ");
    print_list(head);
    pop(&head);
    delete_last(&head);
    printf("Linked list after deleting first and last nodes: ");
    print_list(head);
    delete_node(&head, 3);
    printf("Linked list after deleting node with value 3: ");
    print_list(head);
    return 0;
}