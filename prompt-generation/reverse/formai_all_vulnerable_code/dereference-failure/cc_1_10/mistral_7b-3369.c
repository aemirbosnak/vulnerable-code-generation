//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#define NULL ((void*)0)

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void insert_at_beginning(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(Node** head, int data) {
    Node* new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* current = *head;

    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
}

void delete_node(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->data == data) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;

    while (current->next != NULL && current->next->data != data)
        current = current->next;

    if (current->next == NULL) {
        printf("Element not found\n");
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_beginning(&head, 5);

    print_list(head);

    delete_node(&head, 5);

    print_list(head);

    delete_node(&head, 20);

    print_list(head);

    delete_node(&head, 10);

    print_list(head);

    delete_node(&head, 30);

    print_list(head);

    free(head);

    return 0;
}