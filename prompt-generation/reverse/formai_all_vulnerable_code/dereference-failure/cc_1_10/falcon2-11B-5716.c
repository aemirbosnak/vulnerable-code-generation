//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Function to insert a node at the beginning of a list
void insert_at_beginning(struct node** head, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Function to delete a node from the list
void delete_node(struct node** head, int data) {
    struct node* temp = *head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    if (temp->data == data) {
        *head = temp->next;
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
    printf("Data not found in list\n");
}

int main() {
    // Create a linked list
    struct node* head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 4);
    insert_at_beginning(&head, 5);

    // Print the linked list
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Delete a node from the list
    delete_node(&head, 2);

    // Print the updated linked list
    temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}