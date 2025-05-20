//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void print() {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete(int data) {
    node *current = head;
    node *previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    print();

    delete(3);

    print();

    return 0;
}