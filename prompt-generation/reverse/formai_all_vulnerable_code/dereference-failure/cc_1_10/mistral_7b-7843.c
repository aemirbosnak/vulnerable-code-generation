//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Node {
    char data[MAX_LEN];
    int len;
    struct Node *next;
} Node;

Node *create_node(char *str, int len) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strncpy(new_node->data, str, MAX_LEN);
    new_node->len = len;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(Node **head, Node *new_node) {
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    Node *current = head;
    printf("Linked List:\n");
    while (current != NULL) {
        printf("%s (%d)\n", current->data, current->len);
        current = current->next;
    }
}

Node *reverse_list(Node **head) {
    Node *prev = NULL, *current = *head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return prev;
}

int main() {
    Node *head = NULL;
    Node *node1 = create_node("Hello", 5);
    Node *node2 = create_node("World", 5);
    Node *node3 = create_node("Linked", 7);
    Node *node4 = create_node("List", 4);

    insert_at_beginning(&head, node1);
    insert_at_beginning(&head, node2);
    insert_at_beginning(&head, node3);
    insert_at_beginning(&head, node4);

    print_list(head);

    Node *reversed_head = reverse_list(&head);
    print_list(reversed_head);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(reversed_head);
    free(head);

    return 0;
}