//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a node in a linked list
struct node {
    int data;
    struct node *next;
};

// A function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// A function to insert a node at the beginning of a linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// A function to insert a node at the end of a linked list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// A function to delete a node from the beginning of a linked list
void delete_from_beginning(struct node **head) {
    if (*head == NULL) {
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// A function to delete a node from the end of a linked list
void delete_from_end(struct node **head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *last_node = *head;
    struct node *second_last_node = NULL;
    while (last_node->next != NULL) {
        second_last_node = last_node;
        last_node = last_node->next;
    }
    second_last_node->next = NULL;
    free(last_node);
}

// A function to print a linked list
void print_linked_list(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// A function to free all the nodes in a linked list
void free_linked_list(struct node **head) {
    if (*head == NULL) {
        return;
    }
    struct node *current_node = *head;
    struct node *next_node;
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    *head = NULL;
}

int main() {
    struct node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    print_linked_list(head);
    delete_from_beginning(&head);
    delete_from_end(&head);
    print_linked_list(head);
    free_linked_list(&head);
    return 0;
}