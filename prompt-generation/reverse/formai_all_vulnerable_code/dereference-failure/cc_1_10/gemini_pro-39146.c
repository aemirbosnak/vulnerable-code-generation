//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Linked list operations
struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct Node **head, int data) {
    struct Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void insert_at_position(struct Node **head, int data, int position) {
    struct Node *new_node = create_node(data);
    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    struct Node *current_node = *head;
    int count = 1;
    while (current_node != NULL && count < position - 1) {
        current_node = current_node->next;
        count++;
    }
    if (current_node == NULL) {
        printf("Invalid position\n");
        return;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
}

void delete_at_beginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *current_node = *head;
    struct Node *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (previous_node == NULL) {
        *head = NULL;
    } else {
        previous_node->next = NULL;
    }
    free(current_node);
}

void delete_at_position(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *current_node = *head;
    struct Node *previous_node = NULL;
    int count = 1;
    while (current_node != NULL && count < position) {
        previous_node = current_node;
        current_node = current_node->next;
        count++;
    }
    if (current_node == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (previous_node == NULL) {
        *head = (*head)->next;
    } else {
        previous_node->next = current_node->next;
    }
    free(current_node);
}

void print_list(struct Node *head) {
    struct Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_position(&head, 30, 2);
    insert_at_beginning(&head, 40);
    insert_at_end(&head, 50);
    insert_at_position(&head, 60, 4);
    print_list(head); // Output: 40 10 30 20 60 50
    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_at_position(&head, 3);
    print_list(head); // Output: 10 30 50
    return 0;
}