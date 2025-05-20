//GEMINI-pro DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insert_node_at_head(Node **head, int value) {
    Node *new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

void insert_node_at_tail(Node **head, int value) {
    Node *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void delete_node(Node **head, int value) {
    Node *current_node = *head;
    Node *previous_node = NULL;
    while (current_node != NULL && current_node->value != value) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return;
    }
    if (previous_node == NULL) {
        *head = current_node->next;
    } else {
        previous_node->next = current_node->next;
    }
    free(current_node);
}

bool search_node(Node *head, int value) {
    Node *current_node = head;
    while (current_node != NULL) {
        if (current_node->value == value) {
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

void print_list(Node *head) {
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    insert_node_at_head(&head, 1);
    insert_node_at_head(&head, 2);
    insert_node_at_tail(&head, 3);
    insert_node_at_tail(&head, 4);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    printf("%s\n", search_node(head, 3) ? "true" : "false");
    printf("%s\n", search_node(head, 5) ? "true" : "false");
    return 0;
}