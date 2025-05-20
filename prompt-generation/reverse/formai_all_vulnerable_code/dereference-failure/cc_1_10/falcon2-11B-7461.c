//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the linked list node
struct node {
    int data;
    struct node *next;
};

// Function to insert a new node at the beginning of the list
struct node* insert_at_beginning(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    return (*head_ref);
}

// Function to insert a new node at the end of the list
struct node* insert_at_end(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    struct node* last_node = *head_ref;
    while (last_node->next!= NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
    return *head_ref;
}

// Function to delete a node from the list
void delete_node(struct node** head_ref, int data) {
    struct node* temp = *head_ref;
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }
    if (temp->data == data) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL) {
        if (temp->next->data == data) {
            temp->next = temp->next->next;
            free(temp->next);
            return;
        }
        temp = temp->next;
    }
    printf("Data not found in the list\n");
}

// Function to reverse the list
void reverse_list(struct node** head_ref) {
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Function to display the list
void display_list(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    // Insert nodes at the beginning of the list
    head = insert_at_beginning(&head, 1);
    head = insert_at_beginning(&head, 2);
    head = insert_at_beginning(&head, 3);
    head = insert_at_beginning(&head, 4);
    head = insert_at_beginning(&head, 5);
    head = insert_at_beginning(&head, 6);

    // Insert nodes at the end of the list
    head = insert_at_end(&head, 7);
    head = insert_at_end(&head, 8);
    head = insert_at_end(&head, 9);
    head = insert_at_end(&head, 10);

    // Delete a node from the list
    delete_node(&head, 6);

    // Reverse the list
    reverse_list(&head);

    // Display the list
    display_list(head);

    return 0;
}