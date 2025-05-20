//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_at_beginning(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_position(node **head, int data, int position) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    if (position == 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        node *current = *head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
            if (current == NULL) {
                printf("Invalid position\n");
                return;
            }
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_at_beginning(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        *head = NULL;
        return;
    }
    node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void delete_at_position(node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        delete_at_beginning(head);
        return;
    }
    node *current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
        if (current == NULL) {
            printf("Invalid position\n");
            return;
        }
    }
    node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int main() {
    node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_end(&head, 30);
    insert_at_position(&head, 40, 2);
    print_list(head);
    printf("After deleting the first node:\n");
    delete_at_beginning(&head);
    print_list(head);
    printf("After deleting the last node:\n");
    delete_at_end(&head);
    print_list(head);
    printf("After deleting the node at position 2:\n");
    delete_at_position(&head, 2);
    print_list(head);
    return 0;
}