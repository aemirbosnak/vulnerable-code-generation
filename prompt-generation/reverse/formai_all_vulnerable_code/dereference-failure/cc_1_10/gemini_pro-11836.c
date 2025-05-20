//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
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

void insert_at_position(node **head, int data, int position) {
    if (position == 0) {
        insert_at_beginning(head, data);
    } else {
        node *new_node = create_node(data);
        node *current = *head;
        int count = 0;
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current != NULL) {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

void delete_at_beginning(node **head) {
    if (*head != NULL) {
        node *temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void delete_at_end(node **head) {
    if (*head == NULL) {
        return;
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        node *current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

void delete_at_position(node **head, int position) {
    if (position == 0) {
        delete_at_beginning(head);
    } else {
        node *current = *head;
        int count = 0;
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current != NULL && current->next != NULL) {
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
    insert_at_beginning(&head, 7);
    insert_at_end(&head, 11);
    insert_at_position(&head, 9, 1);
    print_list(head);  // Output: 7 9 11

    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_position(&head, 0);
    print_list(head);  // Output: Empty list

    return 0;
}