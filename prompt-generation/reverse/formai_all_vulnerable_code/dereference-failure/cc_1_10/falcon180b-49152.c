//Falcon-180B DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} Node;

Node *create_node(char *data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(Node **head, char *data) {
    Node *node = create_node(data);
    if (*head == NULL) {
        *head = node;
    } else {
        Node *curr = *head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

void print_list(Node *head) {
    while (head!= NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    add_node(&head, "apple");
    add_node(&head, "banana");
    add_node(&head, "cherry");
    print_list(head);
    Node *curr = head;
    while (curr!= NULL) {
        free(curr->data);
        curr = curr->next;
    }
    free(head);
    return 0;
}