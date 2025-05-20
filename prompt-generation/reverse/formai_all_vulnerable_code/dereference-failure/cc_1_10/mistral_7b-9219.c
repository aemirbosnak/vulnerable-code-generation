//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void error_handler(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        error_handler("Memory allocation failed");
    }

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

bool search_list(Node *head, int data) {
    Node *current = head;

    while (current != NULL) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void delete_node(Node **head, int data) {
    Node *current = *head;
    Node *previous = NULL;

    if (current->data == data) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        error_handler("Element not found in the list");
    }

    previous->next = current->next;
    free(current);
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    insert_at_head(&head, 5);
    insert_at_head(&head, 3);
    insert_at_head(&head, 2);

    print_list(head);

    if (search_list(head, 4)) {
        printf("Element 4 found in the list\n");
    } else {
        printf("Element 4 not found in the list\n");
    }

    delete_node(&head, 3);
    print_list(head);

    delete_node(&head, 5);
    print_list(head);

    return 0;
}