//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char *str;
    size_t len;
    struct Node *next;
} Node;

void print_list(Node *head) {
    Node *current = head;
    printf("%-5s %-15s %-10s\n", "Index", "Data", "String");
    printf("----------------------------------------\n");
    while (current != NULL) {
        printf("%-5d %-15d %-10s\n", current - head, current->data, current->str);
        current = current->next;
    }
}

Node *create_node(int data, size_t len) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->len = len;
    new_node->str = (char *) malloc(len * sizeof(char) + 1);
    strncpy(new_node->str, "", len + 1);
    new_node->next = NULL;
    return new_node;
}

int main() {
    Node *head = NULL;
    Node *temp;

    head = create_node(0, 5);
    temp = head;

    for (int i = 1; i < 10; i++) {
        temp->next = create_node(i, 5);
        temp = temp->next;
    }

    print_list(head);

    Node *current = head;
    while (current != NULL) {
        Node *to_delete = current;
        current = current->next;
        free(to_delete->str);
        free(to_delete);
    }

    return 0;
}