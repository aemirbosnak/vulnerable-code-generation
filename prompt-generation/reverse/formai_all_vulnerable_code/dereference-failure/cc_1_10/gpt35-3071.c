//FormAI DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

/* Define the structure of the list node */
typedef struct list_node {
    int data;
    struct list_node *next;
} list_node;

/* Function to create a new node */
list_node *create_node(int data) {
    list_node *new_node = malloc(sizeof(list_node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: unable to allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to add a new node to the list */
void add_node(list_node **head, int data) {
    /* Create the new node */
    list_node *new_node = create_node(data);

    /* If the list is empty, set the new node as the head */
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    /* Traverse the list to the end and add the new node */
    list_node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

/* Function to remove a node from the list */
void remove_node(list_node **head, int data) {
    /* If the list is empty, there is nothing to remove */
    if (*head == NULL) {
        return;
    }

    /* If the head node needs to be removed, update the head pointer */
    if ((*head)->data == data) {
        *head = (*head)->next;
        return;
    }

    /* Traverse the list to find the node to be removed */
    list_node *prev = *head;
    list_node *current = (*head)->next;
    while (current != NULL) {
        if (current->data == data) {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

/* Function to print the list */
void print_list(list_node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The list contains: ");
    list_node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Main function */
int main() {
    /* Declare the head node */
    list_node *head = NULL;

    /* Add some nodes */
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);

    /* Print the list */
    printf("After adding 3 nodes:\n");
    print_list(head);

    /* Remove a node */
    remove_node(&head, 2);

    /* Print the list again */
    printf("After removing node with data=2:\n");
    print_list(head);

    /* Add another node */
    add_node(&head, 4);

    /* Print the list one more time */
    printf("After adding another node with data=4:\n");
    print_list(head);

    /* Free the memory allocated for the list */
    list_node *current = head;
    while (current != NULL) {
        list_node *temp = current;
        current = current->next;
        free(temp);
    }

    /* Exit the program */
    return 0;
}