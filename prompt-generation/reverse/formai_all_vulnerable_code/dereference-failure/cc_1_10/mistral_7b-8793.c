//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    size_t size;
    struct Node* next;
} Node;

Node* create_node(int data, size_t size) {
    Node* new_node = (Node*)calloc(1, sizeof(Node));

    if (!new_node) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->size = size;
    new_node->next = NULL;

    return new_node;
}

void insert_at_beginning(Node** head_ref, int data, size_t size) {
    Node* new_node = create_node(data, size);

    if (*head_ref != NULL) {
        new_node->next = *head_ref;
    }

    *head_ref = new_node;
}

void delete_node(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        fprintf(stderr, "Key not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display_list(Node* node) {
    while (node != NULL) {
        printf("%d (size: %ld) -> ", node->data, node->size);
        node = node->next;
    }

    printf("NULL\n");
}

void reverse_list(Node** head_ref) {
    Node* prev = NULL, *current = *head_ref, *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

int main() {
    Node* head = NULL;

    insert_at_beginning(&head, 5, sizeof(int));
    insert_at_beginning(&head, 3, sizeof(int));
    insert_at_beginning(&head, 2, sizeof(int));

    printf("Original List: ");
    display_list(head);

    delete_node(&head, 3);
    printf("Deleted 3: ");
    display_list(head);

    reverse_list(&head);
    printf("Reversed List: ");
    display_list(head);

    return EXIT_SUCCESS;
}