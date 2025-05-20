//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: mind-bending
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

void insert_at_head(node **head_ref, int data) {
    node *new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert_at_tail(node **head_ref, int data) {
    node *new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        node *current_node = *head_ref;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void delete_at_head(node **head_ref) {
    if (*head_ref == NULL) {
        printf("Error: List is empty.\n");
        return;
    } else {
        node *current_node = *head_ref;
        *head_ref = (*head_ref)->next;
        free(current_node);
    }
}

void delete_at_tail(node **head_ref) {
    if (*head_ref == NULL) {
        printf("Error: List is empty.\n");
        return;
    } else if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
    } else {
        node *current_node = *head_ref;
        while (current_node->next->next != NULL) {
            current_node = current_node->next;
        }
        free(current_node->next);
        current_node->next = NULL;
    }
}

void print_list(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    } else {
        node *current_node = head;
        while (current_node != NULL) {
            printf("%d -> ", current_node->data);
            current_node = current_node->next;
        }
        printf("NULL\n");
    }
}

int main() {
    node *head = NULL;
    insert_at_head(&head, 10);
    insert_at_tail(&head, 20);
    insert_at_head(&head, 5);
    insert_at_tail(&head, 30);
    printf("Original list:\n");
    print_list(head);
    delete_at_head(&head);
    printf("List after deleting at head:\n");
    print_list(head);
    delete_at_tail(&head);
    printf("List after deleting at tail:\n");
    print_list(head);
    return 0;
}