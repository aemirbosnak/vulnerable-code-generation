//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Create a new node
node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Insert a node after a given node
void insert_after(node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete a node from the end of the list
void delete_from_end(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *current = *head;
    node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(current);
}

// Delete a node from the middle of the list
void delete_from_middle(node **head, node *node_to_delete) {
    if (*head == NULL || node_to_delete == NULL) {
        printf("List is empty or node to delete is NULL\n");
        return;
    }
    node *current = *head;
    node *prev = NULL;
    while (current != node_to_delete) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

// Print the list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Get the length of the list
int get_length(node *head) {
    int length = 0;
    node *current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Reverse the list
node *reverse_list(node *head) {
    node *prev = NULL;
    node *current = head;
    node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Find the middle of the list
node *find_middle(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Check if the list is empty
int is_empty(node *head) {
    return head == NULL;
}

// Main function
int main() {
    // Create an empty list
    node *head = NULL;

    // Insert some data into the list
    insert_at_beginning(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);

    // Print the list
    printf("Original list: ");
    print_list(head);

    // Get the length of the list
    int length = get_length(head);
    printf("Length of the list: %d\n", length);

    // Find the middle of the list
    node *middle = find_middle(head);
    printf("Middle of the list: %d\n", middle->data);

    // Reverse the list
    head = reverse_list(head);
    printf("Reversed list: ");
    print_list(head);

    // Delete a node from the beginning of the list
    delete_from_beginning(&head);
    printf("List after deleting from beginning: ");
    print_list(head);

    // Delete a node from the end of the list
    delete_from_end(&head);
    printf("List after deleting from end: ");
    print_list(head);

    // Delete a node from the middle of the list
    delete_from_middle(&head, middle);
    printf("List after deleting from middle: ");
    print_list(head);

    // Check if the list is empty
    int empty = is_empty(head);
    if (empty) {
        printf("List is empty\n");
    } else {
        printf("List is not empty\n");
    }

    // Free the remaining nodes in the list
    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}