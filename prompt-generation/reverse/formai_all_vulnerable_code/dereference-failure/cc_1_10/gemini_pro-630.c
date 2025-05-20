//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void push(node_t **head, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

node_t* get_nth_node(node_t *head, int n) {
    int i;
    node_t *current = head;
    for (i = 0; i < n && current != NULL; i++) {
        current = current->next;
    }
    return current;
}

void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node_t *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    print_list(head);

    node_t *nth_node = get_nth_node(head, 2);
    if (nth_node != NULL) {
        printf("The 3rd node from the beginning is %d\n", nth_node->data);
    } else {
        printf("The 3rd node from the beginning does not exist\n");
    }

    return 0;
}