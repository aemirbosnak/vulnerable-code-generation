//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Create a node for the linked list
struct node {
    int data;
    struct node *next;
};

// Create a linked list
struct node *create_list(int *arr, int n)
{
    struct node *head = NULL;
    struct node *current = NULL;

    // Iterate over the array and create a node for each element
    for (int i = 0; i < n; i++) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = arr[i];
        new_node->next = NULL;

        // If the head is NULL, set the head to the new node
        if (head == NULL) {
            head = new_node;
            current = new_node;
        }
        // Otherwise, add the new node to the end of the list
        else {
            current->next = new_node;
            current = new_node;
        }
    }

    return head;
}

// Print the linked list
void print_list(struct node *head)
{
    struct node *current = head;

    // Iterate over the list and print each element
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Reverse the linked list
struct node *reverse_list(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;

    // Iterate over the list and reverse the pointers
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Return the new head of the list
    return prev;
}

// Free the linked list
void free_list(struct node *head)
{
    struct node *current = head;
    struct node *next;

    // Iterate over the list and free each node
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    // Create an array of integers
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a linked list from the array
    struct node *head = create_list(arr, n);

    // Print the original linked list
    printf("Original linked list:\n");
    print_list(head);

    // Reverse the linked list
    head = reverse_list(head);

    // Print the reversed linked list
    printf("Reversed linked list:\n");
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}