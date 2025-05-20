//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node **head, int data) {
    if (*head == NULL) {
        *head = create_node(data);
    } else {
        insert_node(&(*head)->next, data);
    }
}

void print_list(node *head) {
    if (head == NULL) {
        printf("[]");
    } else {
        printf("[%d", head->data);
        print_list(head->next);
    }
}

void free_list(node *head) {
    if (head == NULL) {
        return;
    } else {
        free_list(head->next);
        free(head);
    }
}

int main() {
    node *head = NULL;

    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    print_list(head);
    printf("\n");

    free_list(head);

    return 0;
}