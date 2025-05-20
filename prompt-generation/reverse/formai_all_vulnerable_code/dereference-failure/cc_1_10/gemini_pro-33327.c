//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *init_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *insert_at_head(Node *head, int data) {
    Node *new_node = init_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

Node *insert_at_tail(Node *head, int data) {
    Node *new_node = init_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

Node *delete_at_head(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *new_head = head->next;
    free(head);
    return new_head;
}

Node *delete_at_tail(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    head = insert_at_head(head, 1);
    head = insert_at_head(head, 2);
    head = insert_at_head(head, 3);
    head = insert_at_tail(head, 4);
    head = insert_at_tail(head, 5);
    head = insert_at_tail(head, 6);
    print_list(head);  // Output: 3 2 1 4 5 6
    head = delete_at_head(head);
    head = delete_at_tail(head);
    print_list(head);  // Output: 2 1 4 5
    head = delete_at_head(head);
    head = delete_at_tail(head);
    print_list(head);  // Output: 1 4
    head = delete_at_head(head);
    head = delete_at_tail(head);
    print_list(head);  // Output:
    free(head);
    return 0;
}