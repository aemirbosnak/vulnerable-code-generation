//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head_ref, int new_data) {
    Node* new_node = create_node(new_data);
    Node* last = *head_ref;
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void print_list(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    print_list(head);
    return 0;
}