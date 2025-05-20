//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void delete(int data) {
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_list() {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    insert(5);
    insert(10);
    insert(15);
    insert(20);
    printf("List before deletion: ");
    print_list();
    delete(10);
    printf("List after deletion: ");
    print_list();
    return 0;
}