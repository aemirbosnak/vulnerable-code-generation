//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node;

node *create_node(char *data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

void insert_node(node **head, char *data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse_list(node **head) {
    if (*head == NULL) {
        return;
    }
    node *prev = NULL;
    node *current = *head;
    while (current != NULL) {
        node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    node *head = NULL;
    insert_node(&head, "Hello");
    insert_node(&head, "World");
    insert_node(&head, "!");
    print_list(head);
    reverse_list(&head);
    print_list(head);
    return 0;
}