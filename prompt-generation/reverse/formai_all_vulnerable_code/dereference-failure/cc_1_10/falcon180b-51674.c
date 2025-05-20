//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} node_t;

void init_list(node_t** head) {
    *head = NULL;
}

void add_node(node_t** head, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void delete_node(node_t** head, int data) {
    node_t* curr_node = *head;
    while (curr_node!= NULL && curr_node->data!= data) {
        curr_node = curr_node->next;
    }
    if (curr_node == NULL) {
        printf("Node not found\n");
        return;
    }
    node_t* temp_node = curr_node->next;
    free(curr_node);
    curr_node = temp_node;
    *head = curr_node;
}

void print_list(node_t* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node_t* head = NULL;
    init_list(&head);
    add_node(&head, 10);
    add_node(&head, 20);
    add_node(&head, 30);
    print_list(head);
    delete_node(&head, 10);
    print_list(head);
    delete_node(&head, 20);
    print_list(head);
    delete_node(&head, 30);
    print_list(head);
    return 0;
}