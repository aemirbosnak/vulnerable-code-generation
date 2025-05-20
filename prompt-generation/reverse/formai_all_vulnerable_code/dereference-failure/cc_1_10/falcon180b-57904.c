//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    int count;
    struct node *next;
} Node;

Node *create_node(char *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = strdup(data);
    node->count = 1;
    node->next = NULL;
    return node;
}

void insert_node(Node **head, char *data) {
    Node *node = *head;
    while (node!= NULL) {
        if (strcmp(node->data, data) == 0) {
            node->count++;
            return;
        }
        node = node->next;
    }
    node = create_node(data);
    node->next = *head;
    *head = node;
}

void delete_node(Node **head, char *data) {
    Node *node = *head;
    while (node!= NULL && strcmp(node->data, data)!= 0) {
        node = node->next;
    }
    if (node == NULL) {
        return;
    }
    if (node->count == 1) {
        free(node->data);
        free(node);
        *head = node->next;
        return;
    }
    node->count--;
}

void print_list(Node *head) {
    Node *node = head;
    while (node!= NULL) {
        printf("%s (%d)\n", node->data, node->count);
        node = node->next;
    }
}

int main() {
    Node *head = NULL;
    insert_node(&head, "apple");
    insert_node(&head, "orange");
    insert_node(&head, "banana");
    print_list(head);

    delete_node(&head, "orange");
    print_list(head);

    delete_node(&head, "banana");
    print_list(head);

    delete_node(&head, "apple");
    print_list(head);

    return 0;
}