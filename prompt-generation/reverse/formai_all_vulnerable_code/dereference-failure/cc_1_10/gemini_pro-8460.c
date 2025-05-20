//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>

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
        return;
    }
    
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = new_node;
}

void insert_after(node **head, int data, int after_data) {
    node *new_node = create_node(data);
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    node *current = *head;
    while (current != NULL) {
        if (current->data == after_data) {
            new_node->next = current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    }
}

void delete_at_beginning(node **head) {
    if (*head == NULL) {
        return;
    }
    
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(node **head) {
    if (*head == NULL) {
        return;
    }
    
    if ((*head)->next == NULL) {
        free(*head);
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

void delete_after(node **head, int after_data) {
    if (*head == NULL) {
        return;
    }
    
    node *current = *head;
    while (current != NULL) {
        if (current->data == after_data) {
            if (current->next != NULL) {
                node *temp = current->next;
                current->next = temp->next;
                free(temp);
            }
            return;
        }
        current = current->next;
    }
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    
    printf("\n");
}

int main() {
    // Create an empty linked list
    node *head = NULL;
    
    // Insert some data into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_after(&head, 15, 10);
    insert_after(&head, 25, 20);
    
    // Print the linked list
    printf("Linked list: ");
    print_list(head);
    
    // Delete some data from the linked list
    delete_at_beginning(&head);
    delete_at_end(&head);
    delete_after(&head, 15);
    
    // Print the linked list
    printf("Linked list: ");
    print_list(head);
    
    return 0;
}