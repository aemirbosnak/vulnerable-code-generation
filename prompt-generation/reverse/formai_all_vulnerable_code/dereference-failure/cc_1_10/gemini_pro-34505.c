//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Defining a node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Function to create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Couldn't allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node from the linked list (assuming the node to be deleted is not the head node)
void delete_node(node_t **head, node_t *node_to_delete) {
    if (*head == node_to_delete) {
        *head = node_to_delete->next;
        free(node_to_delete);
        return;
    }
    node_t *temp = *head;
    while (temp->next != node_to_delete) {
        temp = temp->next;
    }
    temp->next = node_to_delete->next;
    free(node_to_delete);
}

// Function to traverse the linked list and sum of all elements
int sum_of_all_elements(node_t *head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int main() {
    // Initialize an empty linked list
    node_t *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);

    // Print the linked list
    printf("The linked list is: ");
    node_t *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Delete a node from the linked list
    delete_node(&head, head->next);

    // Print the linked list again
    printf("The linked list after deleting a node is: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Find the sum of all elements in the linked list
    int sum = sum_of_all_elements(head);
    printf("The sum of all elements in the linked list is: %d\n", sum);

    // Free the linked list
    while (head != NULL) {
        node_t *next = head->next;
        free(head);
        head = next;
    }

    return 0;
}