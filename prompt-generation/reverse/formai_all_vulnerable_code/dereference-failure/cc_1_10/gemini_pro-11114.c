//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node;

node *create_node(char *data) {
    node *n = malloc(sizeof(node));
    n->data = strdup(data);
    n->next = NULL;
    return n;
}

void insert_at_head(node **head, char *data) {
    node *n = create_node(data);
    n->next = *head;
    *head = n;
}

void print_list(node *head) {
    while (head) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

void free_list(node *head) {
    while (head) {
        node *next = head->next;
        free(head->data);
        free(head);
        head = next;
    }
}

int main() {
    node *head = NULL;

    insert_at_head(&head, "hello");
    insert_at_head(&head, "world");
    insert_at_head(&head, "!");

    print_list(head);

    free_list(head);

    return 0;
}