//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void delete_node(Node** head, int data) {
    Node* curr_node = *head;
    Node* prev_node = NULL;

    if (curr_node!= NULL && curr_node->data == data) {
        *head = curr_node->next;
        free(curr_node);
        return;
    }

    while (curr_node!= NULL && curr_node->data!= data) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    if (curr_node == NULL)
        return;

    prev_node->next = curr_node->next;
    free(curr_node);
}

int main() {
    Node* head = NULL;

    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    print_list(head);

    delete_node(&head, 3);
    delete_node(&head, 5);

    print_list(head);

    return 0;
}