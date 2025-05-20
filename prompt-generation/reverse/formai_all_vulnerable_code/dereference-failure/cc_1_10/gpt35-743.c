//FormAI DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

/* Define a structure to hold data for each node of the linked list */
struct node {
    int data;
    struct node* next;
};

/* Function to add a node to the end of the linked list */
void append(struct node** head_ref, int new_data) {
    /* Allocate memory for the new node */
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    /* Set the data of the new node */
    new_node->data = new_data;

    /* Set the next pointer of the new node to NULL, as it will be at the end of the list */
    new_node->next = NULL;

    /* If the linked list is empty, make the new node the head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /* Traverse the linked list to find the last node */
    struct node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    /* Set the next pointer of the last node to the new node */
    last_node->next = new_node;
}

/* Function to delete a node from the linked list */
void delete_node(struct node** head_ref, int data_to_delete) {
    /* If the linked list is empty, there is nothing to delete */
    if (*head_ref == NULL) {
        return;
    }

    /* If the node to delete is at the head of the linked list */
    if ((*head_ref)->data == data_to_delete) {
        /* Set the head to the next node in the list */
        struct node* temp = (*head_ref)->next;
        free(*head_ref);
        *head_ref = temp;
        return;
    }

    /* Traverse the linked list to find the node before the one to delete */
    struct node* current = *head_ref;
    while (current->next != NULL && current->next->data != data_to_delete) {
        current = current->next;
    }

    /* If the node to delete was not found in the list */
    if (current->next == NULL) {
        return;
    }

    /* Remove the node from the list */
    struct node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

/* Function to print the values of all nodes in the linked list */
void print_list(struct node* head) {
    /* Traverse the linked list and print the data of each node */
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Main function to test the linked list operations */
int main() {
    /* Initialize an empty linked list */
    struct node* head = NULL;

    /* Append some initial nodes to the list */
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    /* Print the contents of the list */
    printf("Initial list: ");
    print_list(head);

    /* Delete some nodes from the list */
    delete_node(&head, 2);
    delete_node(&head, 4);

    /* Print the contents of the modified list */
    printf("Modified list: ");
    print_list(head);

    return 0;
}