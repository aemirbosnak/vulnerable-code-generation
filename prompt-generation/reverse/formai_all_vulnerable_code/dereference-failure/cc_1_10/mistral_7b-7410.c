//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("[%3d] <-", current->data);
        current = current->prev;
    }
    printf(" NULL\n");

    while (current != NULL) {
        printf("[%3d] ->", current->data);
        current = current->next;
    }
    printf(" NULL\n");
}

void insert_at_head(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head != NULL) {
        new_node->next = *head;
        (*head)->prev = new_node;
    }
    *head = new_node;
}

int main() {
    Node* head = NULL;

    insert_at_head(&head, 5);
    insert_at_head(&head, 3);
    insert_at_head(&head, 1);

    print_list(head);

    return 0;
}