//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Insert a node after a given node
void insert_after(struct node **head, int data, int after_data) {
    struct node *new_node = create_node(data);
    struct node *current = *head;
    while (current != NULL) {
        if (current->data == after_data) {
            new_node->next = current->next;
            current->next = new_node;
            return;
        }
        current = current->next;
    }
    printf("Node with data %d not found\n", after_data);
}

// Delete a node from the beginning of the list
void delete_at_beginning(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_at_end(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *current = *head;
    struct node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        *head = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
}

// Delete a node from the middle of the list
void delete_node(struct node **head, int data) {
    struct node *current = *head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Node with data %d not found\n", data);
}

// Print the list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Reverse the list
struct node *reverse_list(struct node *head) {
    struct node *current = head;
    struct node *previous = NULL;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

// Find the middle of the list
struct node *find_middle(struct node *head) {
    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Main function
int main() {
    struct node *head = NULL;

    // Insert some nodes into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_after(&head, 3, 1);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Reverse the list
    head = reverse_list(head);

    // Print the reversed list
    printf("Reversed list: ");
    print_list(head);

    // Find the middle of the list
    struct node *middle = find_middle(head);
    printf("Middle of the list: %d\n", middle->data);

    // Delete a node from the beginning of the list
    delete_at_beginning(&head);

    // Print the list after deleting a node from the beginning
    printf("List after deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    delete_at_end(&head);

    // Print the list after deleting a node from the end
    printf("List after deleting a node from the end: ");
    print_list(head);

    // Delete a node from the middle of the list
    delete_node(&head, 3);

    // Print the list after deleting a node from the middle
    printf("List after deleting a node from the middle: ");
    print_list(head);

    return 0;
}