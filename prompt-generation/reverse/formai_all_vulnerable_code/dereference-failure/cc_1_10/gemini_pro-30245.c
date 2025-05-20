//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
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

void insert_at_index(node **head, int data, int index) {
    if (index == 0) {
        insert_at_beginning(head, data);
    } else {
        node *new_node = create_node(data);
        node *current = *head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_node(node **head, int data) {
    if (*head == NULL) {
        return;
    } else if ((*head)->data == data) {
        *head = (*head)->next;
    } else {
        node *current = *head;
        while (current->next != NULL && current->next->data != data) {
            current = current->next;
        }
        if (current->next != NULL) {
            node *temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_index(&head, 3, 1);
    print_list(head); // Output: 1 3 2
    delete_node(&head, 2);
    print_list(head); // Output: 1 3
    return 0;
}