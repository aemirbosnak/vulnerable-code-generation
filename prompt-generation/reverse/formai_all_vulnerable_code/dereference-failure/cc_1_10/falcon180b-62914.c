//Falcon-180B DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(node** head, int data) {
    node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void delete_node(node** head, int data) {
    node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node not found!");
        return;
    }
    node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    free(node_to_delete);
}

void print_list(node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    delete_node(&head, 1);
    print_list(head);
    delete_node(&head, 3);
    print_list(head);
    return 0;
}