//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void print_list(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *current_node = head;
    printf("List: ");
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void delete_node(node **head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *current_node = *head;
    node *previous_node = NULL;
    while (current_node != NULL) {
        if (current_node->data == data) {
            if (previous_node == NULL) {
                *head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            break;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        printf("Node not found.\n");
    }
}

int main() {
    node *head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);
    print_list(head);
    delete_node(&head, 3);
    print_list(head);
    delete_node(&head, 5);
    print_list(head);
    delete_node(&head, 1);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    delete_node(&head, 4);
    print_list(head);
    return 0;
}