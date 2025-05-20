//FormAI DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(Node** head, int data) {
    Node* node = create_node(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

void insert_node(Node** head, int data, int position) {
    Node* node = create_node(data);
    if (*head == NULL || position == 0) {
        node->next = *head;
        *head = node;
        return;
    }
    Node* current = *head;
    int count = 0;
    while (current->next != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    node->next = current->next;
    current->next = node;
}

void delete_node(Node** head, int data) {
    Node* current = *head;
    Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void reverse_list(Node** head) {
    Node* previous = NULL;
    Node* current = *head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}

void print_list(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    printf("List after adding 3 nodes: ");
    print_list(head);
    insert_node(&head, 4, 1);
    printf("List after inserting node with data 4 at position 1: ");
    print_list(head);
    delete_node(&head, 2);
    printf("List after deleting node with data 2: ");
    print_list(head);
    reverse_list(&head);
    printf("List after reversing: ");
    print_list(head);
    return 0;
}