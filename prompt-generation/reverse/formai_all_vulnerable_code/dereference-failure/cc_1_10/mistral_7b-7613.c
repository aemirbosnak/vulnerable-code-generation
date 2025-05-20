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
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_at_head(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_position(Node** head, int position, int data) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        insert_at_head(head, data);
        return;
    }

    Node* current = *head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }

    Node* new_node = create_node(data);
    new_node->next = current->next;
    current->next = new_node;
}

void delete_at_head(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_position(Node** head, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) {
        delete_at_head(head);
        return;
    }

    Node* current = *head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    insert_at_head(&head, 1);
    insert_at_head(&head, 2);
    insert_at_position(&head, 2, 3);
    print_list(head);

    delete_at_head(&head);
    delete_at_position(&head, 1);
    print_list(head);

    return 0;
}