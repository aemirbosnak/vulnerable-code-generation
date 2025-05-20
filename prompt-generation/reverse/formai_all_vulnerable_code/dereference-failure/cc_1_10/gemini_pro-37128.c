//GEMINI-pro DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of a linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of a linked list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a node after a given node
void insert_after(struct node **head, int data, int after) {
    struct node *new_node = create_node(data);
    struct node *temp = *head;
    while (temp != NULL) {
        if (temp->data == after) {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete a node from the beginning of a linked list
void delete_from_beginning(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of a linked list
void delete_from_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
}

// Function to delete a node from a given position
void delete_from_position(struct node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    struct node *prev = NULL;
    int count = 1;
    while (temp != NULL) {
        if (count == position) {
            break;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to print the linked list
void print_linked_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(&head, 30, 10);
    print_linked_list(head);
    delete_from_beginning(&head);
    delete_from_end(&head);
    delete_from_position(&head, 2);
    print_linked_list(head);
    return 0;
}