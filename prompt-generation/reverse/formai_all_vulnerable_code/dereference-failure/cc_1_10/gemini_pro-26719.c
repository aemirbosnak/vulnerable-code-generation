//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *insert_at_beginning(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

Node *insert_at_end(Node *head, int data) {
    if (head == NULL) {
        return create_node(data);
    } else {
        head->next = insert_at_end(head->next, data);
        return head;
    }
}

Node *insert_at_position(Node *head, int data, int position) {
    if (position == 0) {
        return insert_at_beginning(head, data);
    } else {
        head->next = insert_at_position(head->next, data, position - 1);
        return head;
    }
}

Node *delete_at_beginning(Node *head) {
    if (head == NULL) {
        return NULL;
    } else {
        Node *next_node = head->next;
        free(head);
        return next_node;
    }
}

Node *delete_at_end(Node *head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL) {
        free(head);
        return NULL;
    } else {
        head->next = delete_at_end(head->next);
        return head;
    }
}

Node *delete_at_position(Node *head, int position) {
    if (position == 0) {
        return delete_at_beginning(head);
    } else if (head->next == NULL) {
        return NULL;
    } else {
        head->next = delete_at_position(head->next, position - 1);
        return head;
    }
}

void print_list(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("%d ", head->data);
        print_list(head->next);
    }
}

int main() {
    Node *head = NULL;

    head = insert_at_beginning(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_position(head, 30, 1);

    print_list(head);  // Output: 10 30 20

    head = delete_at_beginning(head);
    head = delete_at_end(head);
    head = delete_at_position(head, 0);

    print_list(head);  // Output: List is empty.

    return 0;
}