//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void create_list(node_t** head, int size) {
    node_t* curr = *head;
    for (int i = 0; i < size; i++) {
        node_t* new_node = (node_t*) malloc(sizeof(node_t));
        new_node->data = i;
        new_node->next = NULL;
        if (*head == NULL) {
            *head = new_node;
            curr = *head;
        } else {
            curr->next = new_node;
            curr = curr->next;
        }
    }
}

void print_list(node_t* head) {
    node_t* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void reverse_list(node_t** head) {
    node_t* prev = NULL;
    node_t* curr = *head;
    while (curr!= NULL) {
        node_t* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void main() {
    node_t* head = NULL;
    create_list(&head, 5);
    print_list(head);
    reverse_list(&head);
    print_list(head);
}