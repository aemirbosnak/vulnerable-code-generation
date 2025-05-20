//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *create_node(char *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

void insert_node(Node **head, Node *node) {
    if (*head == NULL) {
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

void free_list(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head->data);
        free(head);
        head = next;
    }
}

int main() {
    Node *head = NULL;

    insert_node(&head, create_node("Hello"));
    insert_node(&head, create_node("World"));
    insert_node(&head, create_node("!"));

    print_list(head);

    free_list(head);

    return 0;
}