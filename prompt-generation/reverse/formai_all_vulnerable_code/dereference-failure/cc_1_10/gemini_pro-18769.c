//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void print_list(node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("%d ", head->data);
    print_list(head->next);
}

node *insert_at_head(node *head, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

node *insert_at_tail(node *head, int data) {
    if (head == NULL) {
        return insert_at_head(head, data);
    }
    head->next = insert_at_tail(head->next, data);
    return head;
}

node *delete_at_head(node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    node *new_head = head->next;
    free(head);
    return new_head;
}

node *delete_at_tail(node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    head->next = delete_at_tail(head->next);
    return head;
}

int main() {
    node *head = NULL;

    head = insert_at_head(head, 1);
    head = insert_at_tail(head, 2);
    head = insert_at_tail(head, 3);
    head = insert_at_tail(head, 4);
    head = insert_at_tail(head, 5);

    print_list(head);

    head = delete_at_head(head);
    head = delete_at_tail(head);

    print_list(head);

    return 0;
}