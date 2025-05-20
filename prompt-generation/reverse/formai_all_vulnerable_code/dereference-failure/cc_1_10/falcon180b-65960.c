//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* create_node(int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(node_t** head, int data) {
    node_t* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void print_list(node_t* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
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

void delete_node(node_t** head, int data) {
    node_t* curr = *head;
    node_t* prev = NULL;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Node not found.\n");
        return;
    }
    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

int main() {
    node_t* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);
    printf("Original list:\n");
    print_list(head);
    reverse_list(&head);
    printf("Reversed list:\n");
    print_list(head);
    delete_node(&head, 3);
    printf("List after deleting node with data 3:\n");
    print_list(head);
    return 0;
}