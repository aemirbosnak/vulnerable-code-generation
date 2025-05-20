//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert_at_head(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_tail(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_at_head() {
    if (head == NULL) {
        return;
    }
    node *to_delete = head;
    head = head->next;
    free(to_delete);
}

void delete_at_tail() {
    if (head == NULL) {
        return;
    }
    node *current = head;
    node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        head = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
}

void print_list() {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert_at_head(1);
    insert_at_tail(2);
    insert_at_head(3);
    insert_at_tail(4);
    print_list();
    delete_at_head();
    delete_at_tail();
    print_list();
    return 0;
}