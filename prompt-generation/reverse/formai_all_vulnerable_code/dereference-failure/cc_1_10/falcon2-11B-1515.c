//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head;

void add_node(int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void remove_node(int value) {
    Node *current = head;
    Node *prev = NULL;

    while (current!= NULL && current->data!= value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void print_list() {
    Node *current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    add_node(5);
    add_node(10);
    add_node(15);
    print_list();

    remove_node(10);
    print_list();

    return 0;
}